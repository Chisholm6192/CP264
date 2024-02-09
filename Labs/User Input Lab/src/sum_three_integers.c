/**
 * -------------------------------------
 * @file  functions.c
 * Lab 2 Functions Source Code File
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-02-02
 *
 * -------------------------------------
 */
#include "functions.h"

int sum_three_integers(void) {
    char input[100];

    //variables for sum, valid and number of digits
    int sum = 0;
    int valid = 0;
    int numDigits = 0;

    printf("Enter three comma-separated integers: ");
    scanf("%s", &input);

    while (valid == 0){ //if the entered sequence is not valid, keep running
        numDigits = 0; //reset number of digits and sum each time a new request is sent
        sum = 0;
        int i = 0;

        while (*(input + i) != '\0' && (isdigit(*(input + i)) || *(input + i) == ',')){ 
            //loop runs until string end it reached, or a non digit value is found, that is not a coma, and three digits haven't been found yet

            if (isdigit(*(input + i))){ 
                //only add to sum if the input is a digit
                numDigits++;
                sum += (int)(*(input + i)) - 48;

            }
            i++;
        }

        if (numDigits == 3){
            valid = 1;
            //if three digits have been found, end loop
        }

        else{
            //if numbers weren't entered correctly, ask again
            printf("The integers were not properly entered.\n");
            printf("Enter three comma-separated integers: ");
            scanf("%s", &input);
        }
    }

    return sum;
}