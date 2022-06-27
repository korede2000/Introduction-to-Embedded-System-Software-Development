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
 *	
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
  int median = 0;
  int mean = 0;
  int maximum = 0;
  int minimum = 0;
  
  /* Statistics and Printing Functions Go Here */
  
  // Print little code description
  printf("A simple c-Programming example to write a couple of functions that can\n");
  printf("analyze an array of unsigned char data items and report analytics on the\n"); 
  printf("given data then return the maximum, minimum, mean, and median\n\n");
  
  // print the original data to the screen
  printf("\nArray of data item before sorting: \n");
  print_array(test , SIZE);
  printf("\n");
  
  // Sort the array in ascending order and print it
  sort_array(test, SIZE);
  printf("Array of data item after sorting: \n");
  print_array(test, SIZE);
  printf("\n");
  
  // Pass the sorted array to calculate the median of your array
  median = find_median(test, SIZE);
  mean = find_mean(test, SIZE);
  maximum = find_maximum(test, SIZE);
  minimum = find_minimum(test, SIZE);
  
  // Print the statistics data
  print_statistics (minimum, maximum, mean, median);
  
}

void print_statistics (unsigned int minimum, unsigned int maximum, 
			int mean, unsigned int median){
  printf("\nThe minimum number is: %d \n", minimum);
  printf("\nThe maximum number is: %d \n", maximum);
  printf("\nThe mean of the array is: %d \n", mean);
  printf("\nThe median of the set of data is: %d \n", median);
}

void print_array (unsigned char *ptest, int length){
  int count = 0;
  for (int i=0; i<length; i++){  
    printf("%d, ", *(ptest + i));
    count++;
    if ( count ==10 ){
      printf("\n");
      count =0;
    }
  }
  printf("\n");
}

int find_median (unsigned char array[], int length){
  int median = 0;
  // if number of data set is even
  if( length % 2 == 0 )
    median = ( array[(length-1)/2] + array[length/2] ) / 2.0;
  // if number of dataset is odd
  else
    median = array[length/2];
  return median;
}

int find_mean (unsigned char *ptest, int length) {
  unsigned int sum = 0;
  int mean = 0;
  for( int i=0; i<length; i++ ){
    sum += ptest[i];
    mean = sum/length;
  }
  return mean;
}

//This function uses the sorted array to find the maximum
int find_maximum (unsigned char array[], int length) {
  int maximum = array[0];
  return maximum;
}

//This function uses the sorted array to find the minimum
int find_minimum (unsigned char array[], int length) {
  int minimum = array[length-1];
  return minimum;
}

void sort_array (unsigned char *ptest, int length) {
  for (int i=0; i< length; i++) {
    for (int j=0; j<length; ++j) {
      if (ptest[i] > ptest[j]) {
        int a = ptest[i];
        ptest[i] = ptest[j];
        ptest[j] = a;
      }
    }
  }
}
