#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# This is the second assignment in the course. Its a maefile to automate the build process.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <file>.i -->    This generarates the preprocessed file from the corresponding C file
#      <file>.asm -->  Generate assembly output of c-program implementation files and the final output executable 
#      <file>.o -->    Generate the object file for all c-source files (without linking) by specifying the object file you want to compile.
#      compile-all --> Compiles all the src files without lliking and generates the corresponding object files.
#      build -->       Compiles all object files and link into a final executable.	
#      clean -->       This removes all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
#
# Platform Overrides:
#      This makefile supports 2 platforms: the host linux machine, and the MSP432 MCU.
#      For the MSP432, we define its specific linker(msp432p40lr.lds), the CPU, architecture which differs from that of the "host" platform.
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = HOST
BASENAME = c1m2
TARGET = $(BASENAME).out

# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	SOURCES+= 	./startup_msp432p401r_gcc.c \
				./system_msp432p401r.c \
				./interrupts_msp432p401r_gcc.c
	
	INCLUDES+= 	-I ../include/CMSIS/ \
				-I ../include/msp432/
	# Compiler
	CC = arm-none-eabi-gcc

	# Linker
	LD = arm-none-eabi-ld
	SIZE = arm-none-eabi-size
	LINKER_FILE = ../msp432p401r.lds
	LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
	
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -Werror -O0 -g -std=c99 \
				--specs=nosys.specs
			
	CPPFLAGS = -DMSP432 $(INCLUDES)

else
	CC = gcc
	CFLAGS = -Wall -Werror -g -O0 -std=c99
	CPPFLAGS = -DHOST $(INCLUDES)
	SIZE = size
	
endif


#Other declared variables
OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.s)
PPS = $(SOURCES:.c=.i) 
DEPS = $(SOURCES:.c=.d)	

#------------------------------------------------------------------------------
# Target: <file>.i
# Prerequisite: the .c file
# Output: the .d as well as .i files
#------------------------------------------------------------------------------
# The -E stops after preprocessing stage, do not compile
%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) -o $@

#------------------------------------------------------------------------------
# Target: <file>.asm
# Prerequisite: the .c file
# Output: the .asm file from the .c file
#------------------------------------------------------------------------------
%.asm : %.c
## The -S stops after compiling the file but do not link
%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) -o $@
	
#------------------------------------------------------------------------------
# Target: <file>.o
# Prerequisite: the .c file
# Output: the .o file from the corresponding .c file
#------------------------------------------------------------------------------
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) -o $@

#------------------------------------------------------------------------------
# Target: <file>.o
# Prerequisite: the .c file
# Output: the .o file from the corresponding .c file
#------------------------------------------------------------------------------
%.d: %c
	$(CC) -E -M $<  $(CPPFLAGS) -o $@
#------------------------------------------------------------------------------

# Target: compile-all
# Prerequisite: the .c file
# Output: all source files are compiled but not linked, 
#	  their corresponding .o files is generated from .c files
#------------------------------------------------------------------------------
.PHONY: compile-all
# OBJ here is the SRCS
compile-all: $(OBJS)
	$(CC) -c $(SOURCES) $(OBJS) $(DEFINEFLAG)  $(CFLAGS) $(CPPFLAGS)  -o $@

#------------------------------------------------------------------------------
# Target: build
# Prerequisite: the .c file
# Output: the final executable file after linking and a brief report regarding the application size	  
#------------------------------------------------------------------------------
.PHONY: build
build: $(TARGET)
$(TARGET): $(OBJS)
	$(CC)  $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ 
	$(SIZE) $@
	
#------------------------------------------------------------------------------
# Target: clean
# Prerequisite: None
# Output: all generated files are removed and the directory is cleaned for a new build
#------------------------------------------------------------------------------
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS) $(BASENAME) $(ASMS) $(PPS) *.i *.map *.s *.out *.o *.Makefile ./-MD ./-M ./-W ./-MF ./objdump ./bjdump 
	

