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
# PLATFORM = 
BASENAME = clm2
TARGET = $(BASENAME).out

# Architectures Specific Flags
ifeq ($(PLATFORM), MSP432)
	LINKER_FILE = -T ../msp432P401r.lds
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
else
	CPU = x86_64
	ARCH:=$(shell arch)
endif


# Compiler Flags and Defines
ifeq ($(PLATFORM), MSP432)
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	## -Wl: Pass option to linker from compiler, -Map: Output a memory map file from the result of linking
	LDFLAGS = -W $(LINKER_FILE)
	## -Wall: Enables all warning messages, -Werror: Treat all warnings as errors 
	CFLAGS = -mcpu=$(CPU) -march=$(ARCH) --specs=$(SPECS) -mfloat-abi=hard -mfpu=fpv4-sp-d16 -mthumb -Wall -Werror -O0 -g -std=c99
	CPPFLAGS = -M -MF -MD 
	DEFINEFLAG = -DMSP432
else
	CC = gcc
	#LD = 
	LDFLAGS = -W
	CFLAGS = -Wall -Werror -O0 -g -std=c99
	CPPFLAGS = -M -MF -MD 
	DEFINEFLAG = -DHOST
	#INCLUDES= -include../includes/common/platform.h
endif

#Other declared variables
OBJS = $(SOURCES:.c=.o)
ASMS = $(SOURCES:.c=.s)
PPS = $(SOURCES:.c=.i) 

#------------------------------------------------------------------------------
# Target: <file>.i
# Prerequisite: the .c file
# Output: the .d as well as .i files
#------------------------------------------------------------------------------
%.i : %.c
# The -E stops after preprocessing stage, do not compile
	$(CC) $(CPPFLAGS) $(DEFINEFLAG) $<  $(CFLAGS) -E -o $@  
	
#------------------------------------------------------------------------------
# Target: <file>.asm
# Prerequisite: the .c file
# Output: the .asm file from the .c file
#------------------------------------------------------------------------------
%.asm : %.c
## The -S stops after compiling the file but do not link
	$(CC) $(DEFINEFLAG) $<  $(CFLAGS) -S -objdump 
	
#------------------------------------------------------------------------------
# Target: <file>.o
# Prerequisite: the .c file
# Output: the .o file from the corresponding .c file
#------------------------------------------------------------------------------
%.o : %.c
	$(CC) $(DEFINEFLAG) $<  $(CFLAGS) -c 

#------------------------------------------------------------------------------
# Target: compile-all
# Prerequisite: the .c file
# Output: all source files are compiled but not linked, 
#	  their corresponding .o files is generated from .c files
#------------------------------------------------------------------------------
.PHONY: compile-all
# OBJ here is the SRCS
compile-all: $(OBJS)
	$(CC) $(SOURCES) $(OBJS) $(DEFINEFLAG)  $(CFLAGS) -c $@

#------------------------------------------------------------------------------
# Target: build
# Prerequisite: the .c file
# Output: the final executable file after linking and a brief report regarding the application size	  
#------------------------------------------------------------------------------
.PHONY: build
build: $(TARGET)
$(TARGET) : $(OBJS)
	$(CC) $(DEFINEFLAG) $(SOURCES) $(OBJS) $(CFLAGS) -o $@  $(LDFLAGS) $^ 
	size $(TARGET)
	
#------------------------------------------------------------------------------
# Target: clean
# Prerequisite: None
# Output: all generated files are removed and the directory is cleaned for a new build
#------------------------------------------------------------------------------
.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJS) $(BASENAME) $(ASMS) $(PPS) *.i *.map *.s *.out *.o *.Makefile ./-MD ./-M ./-W ./-MF ./objdump ./bjdump 
	

