/**
 * -------------------------------------
 * @file  by_ptr.c
 * Lab 2 Pointer Functions Header File
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

#ifndef BY_PTR_H_
#define BY_PTR_H_

// Prototypes.

/**
 * Populates values with consecutive integers in the range [1 to size].
 * Uses pointer arithmetic.
 *
 * @param values - array of int
 * @param size - size of values
 */
void fill_values_by_ptr(int *values, int size) {
    for(int i = 0; i < size; i++) {
        *(values + i) = i + 1;
    }
}

/**
 * Populates squares with the squares of the corresponding integers in values.
 * Uses pointer arithmetic.
 *
 * @param values - array of int
 * @param squares - array of int, each a square of corresponding int in values
 * @param size - size of values and squares
 */
void fill_squares_by_ptr(int *values, long int *squares, int size) {
    for (int i = 0; i < size; i++){
        *(squares + i) = *(values + i) * *(values + i);
    }
}

/**
 * Prints the contents of values and squares in two columns.
 * Uses pointer arithmetic.
 *
 * @param values - array of int
 * @param squares - array of int, each a square of corresponding int in values
 * @param size - size of values and squares
 */
void print_by_ptr(int *values, long int *squares, int size) {
    fill_values_by_ptr(values, size);
    fill_squares_by_ptr(values, squares, size);

    printf("Value Square\n");
    printf("----- ----------\n");
    for (int i = 0; i < size; i++){
        printf("%5d ", *(values + i));
        printf("%10d\n", *(squares + i));
    }
}

#endif /* BY_PTR_H_ */
