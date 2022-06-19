/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 * *****************************************************************************/

/****************************************************************************
 * @file Stats.c
 * @brief Statistical Analysis on a given set of data
 *
 * @author Abdul Fattah Molade
 * @date   Edited June 19, 2022 
 *
 * A simple c-Programming example to write a couple of functions that can 
 *  analyze an array of unsigned char data items and report analytics on the 
 *  given data then return the:
 *	-Maximum
 *	-Minimum
 *	-Mean
 *	-Median
 *	-Number Histogram 
 ***************************************************************************/



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

}

void print_statistics (int *ptr) {

}

void print_array (int *ptr) {

}

int find_median (int *ptr, int length) {
  return 0;
}

int find_mean (int *ptr, int length) {
  return 0;
}

int find_maximum (int *ptr, int length) {
  return 0;
}

int find_minimum (int *ptr, int length) {
  return 0;
}

void sort_array (int *ptr, int length) {

}
