/*
--------------------------------------------------
File:    mysort.c, 
About:   public test driver
Author:  Ryan Chisholm, 169027577, chis7577@mylaurier.ca
Version: 2024-02-07
--------------------------------------------------
*/

#include "mysort.h"

/**
 * Use selection sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void select_sort_inc(float *a[], int left, int right) {
    int i, j, k;
    float *temp;

    for (i = left; i < right; i++){ //iterate through selected intervals
        k = i;
        for (j = i + 1; j < right; j++){ //traverse remainder of array to compare with a[i]
            if(*a[j] < *a[k]){ //update current minimum value
                k = j;
            }
        }
        if (i != k){ //swap indexes
            temp = a[k];
            a[k] = a[i];
            a[i] = temp;
        }
    }
}


/**
 * Use quick sort algorithm to sort array of float pointers such that their pointed values are incresing order.
 *
 * @param *a[] - array of float pointers.
 * @param left - the start index of float pointer in array.
 * @param right - the end index of float pointer in array
 */
void quick_sort_inc(float *a[], int left, int right) {
    int i,j;
    float pivot, *temp;

    if(left < right){
        pivot = *a[left]; //set pivot to be left index
        i = left+1;
        j = right;

        while (i <= j){ //run until i and j meet in middle
            while(i <= right && *a[i] <= pivot) i++; //run until value greater than pivot is found
            while(j >= left && *a[j] > pivot) j--; //run until value less than pivot is found
            if(i < j) { //if i has a smaller index than j, swap them
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        //swap left index and value at index j
        temp = a[left];
        a[left] = a[j];
        a[j] = temp;

        //call sorting method again, to iterate through left and right sides of array
        quick_sort_inc(a, left, j-1);
        quick_sort_inc(a, j+1, right);
    }
}