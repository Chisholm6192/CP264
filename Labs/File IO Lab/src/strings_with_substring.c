/**
 * -------------------------------------
 * @file  strings_with_substring.c
 * Lab 4 Source Code File
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-02-03
 *
 * -------------------------------------
 */
#include "functions.h"

void strings_with_substring(strings_array *data, char *substr) {
    for(int i = 0; i < data->lines; i++){
        if (strstr(data->strings[i], substr) != NULL){
            printf("%s\n", data->strings[i]);
        }
    }
}
