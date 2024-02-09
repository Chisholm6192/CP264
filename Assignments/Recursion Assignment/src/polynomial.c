/**
 * -------------------------------------
 * @file  polynomial.c
 * 
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-01-23
 *
 * ------------------------------------- */ 

#include <stdio.h>
#include <math.h>
#include "polynomial.h"

#define EPSILON 1e-6


float horner(float *p, int n, float x) {
    float total = 0;

    for (int i = 0; i < n; i++){
        total += p[i] * pow(x, n-(i+1));
    }

    return total;
}

float bisection(float *p, int n, float a, float b) {
    float c = (a + b) / 2;
}