/**
 * -------------------------------------
 * @file  int_array_read.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-02-02
 *
 * -------------------------------------
 */
#include "functions.h"

void int_array_read(int *array, int size) {
    char input;
    int numDigits = 0;

    printf("Enter %d values for an array of int.\n", size);

    while (numDigits < size){
        //run until enough digits have been entered to fill array

        printf("Value for index %d: ", numDigits);
        scanf(" %c", &input);

        if (isdigit(input)){
            *(array + numDigits) = (int) (input) - 48; //insert digits, as integer into the array
            numDigits += 1;
        }
        else {
            printf("Not a valid integer\n");
        }
    }
}