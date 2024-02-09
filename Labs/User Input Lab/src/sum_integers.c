/**
 * -------------------------------------
 * @file  sum_integers.c
 * Lab 3 Source Code File
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-02-02
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_integers(void) {
    char input; //character input
    char num;
    int sum = 0;

    printf("Enter integers, one per line: ");
    gets(&input);

    while (isdigit(input)){ //run until a non digit character is entered
        num = input; //load input value onto secondary char variable
        sum += (int)(num) - 48; //convert to integer and add to sum
        //the reason I used num is because, doing a typecast using the input variable, changes it to an integer, causing issues in subsequent iterations
        gets(&input);
    }

    return sum;
}