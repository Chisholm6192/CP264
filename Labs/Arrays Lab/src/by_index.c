/**
 * -------------------------------------
 * @file  by_index.c
 * Lab 2 Index Functions Header File
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-01-23
 *
 * -------------------------------------
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef BY_INDEX_H_
#define BY_INDEX_H_

// Prototypes.

/**
 * Populates values with consecutive integers in the range [1 to size].
 * Uses array indexing.
 *
 * @param values - array of int
 * @param size - size of values
 */
void fill_values_by_index(int values[], int size) {
    for(int i = 0; i < size; i++) {
        values[i] = i + 1;
    }
}

/**
 * Populates squares with the squares of the corresponding integers in values.
 * Uses array indexing.
 *
 * @param values - array of int
 * @param squares - array of int, each a square of corresponding int in values
 * @param size - size of values and squares
 */
void fill_squares_by_index(int values[], long int squares[], int size){
    for (int i = 0; i < size; i++){
        squares[i] = values[i] * values[i];
    }
}

/**
 * Prints the contents of values and squares in two columns.
 * Uses array indexing.
 *
 * @param values - array of int
 * @param squares - array of int, each a square of corresponding int in values
 * @param size - size of values
 */
void print_by_index(int values[], long int squares[], int size){
    fill_values_by_index(values, size);
    fill_squares_by_index(values, squares, size);

    printf("Value Square\n");
    printf("----- ----------\n");
    for (int i = 0; i < size; i++){
        printf("%5d ", values[i]);
        printf("%10d\n", squares[i]);
    }

}

#endif /* BY_INDEX_H_ */
