/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h 
 * @brief Statistical Analysis on a given set of data
 *
 * @author Abdul Fattah Molade
 * @date   Edited June 19, 2022
 *
 */
#ifndef __STATS_H__
#define __STATS_H__



/**************************************************************************
 * Function: print_statistics
 * Description:
 * 	This function takes as an input a given set of array and prints the 
 *	statistics of the array including the minimum, maximum, mean, and 
 *	median.
 * Parameters:
 *	int *ptr: Pointer to a data set
 * Return:
 *	void
 *************************************************************************/
void print_statistics (unsigned int minimum, unsigned int maximum, 
			int mean, unsigned int median) ;

/**************************************************************************
 * Function: print_array
 * Description:
 * 	This function takes as an input a given set of array and prints the 
 *	array to the screen
 * Parameters:
 *	unsigned char *ptest: Pointer to a data set
 * Return: void
 *************************************************************************/
void print_array (unsigned char *ptest, int length) ;

/**************************************************************************
 * Function: find_median
 * Description:
 * 	This function takes as an input a given set of array and a length 
 *	then returns the median
 * Parameters:
 *	int *ptr: Pointer to a data set
 	int length: The length of the array
 * Return: median
 *************************************************************************/
int find_median (unsigned char array[], int length);

/**************************************************************************
 * Function: find_mean
 * Description:
 * 	This function takes as an input a given set of array and a length 
 *	then returns the mean of the data set
 * Parameters:
 *	int *ptr: Pointer to a data set
 	int length: The length of the array
 * Return: median
 *************************************************************************/
int find_mean (unsigned char *ptest, int length);

/**************************************************************************
 * Function: find_maximum
 * Description:
 * 	This function takes as an input a given set of array and a length 
 *	then returns the maxinum number 
 * Parameters:
 *	int *ptr: Pointer to a data set
 	int length: The length of the array
 * Return: maximum
 *************************************************************************/
int find_maximum (unsigned char array[], int length);

/**************************************************************************
 * Function: find_minimum
 * Description:
 * 	This function takes as an input a given set of array and a length 
 *	then returns the minimum number
 * Parameters:
 *	int *ptr: Pointer to a data set
 	int length: The length of the array
 * Return: minimum
 *************************************************************************/
int find_minimum (unsigned char array[], int length);

/**************************************************************************
 * Function: sort_array
 * Description:
 * 	This function takes as an input a given set of array and a length 
 *	then sorts the array from largest to smallest
 * Parameters:
 *	unsigned char ptest: Pointer to a data set
 	int length: The length of the array
 * Return: void
 *************************************************************************/
void sort_array (unsigned char *ptest, int length) ;

#endif /* __STATS_H__ */
