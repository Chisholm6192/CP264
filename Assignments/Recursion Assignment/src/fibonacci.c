/**
 * -------------------------------------
 * @file  fibonacci.c
 * 
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-01-23
 *
 * ------------------------------------- */
#include "fibonacci.h"

/**
 *  recursive_fibonacci()
 * Parameters: int n, the fibonacci term to be computed
 * Returns: int, the value at term n of the sequence
 */
int recursive_fibonacci(int n) {
    if (n == 1 || n == 0){
        return n;
    }

    else {
        return recursive_fibonacci(n-1) + recursive_fibonacci(n-2);
    }
}

/**
 *  iterative_fibonacci()
 * Parameters: int n, the fibonacci term to be computed
 * Returns: int, the value at term n of the sequence
 */
int iterative_fibonacci(int n){ 
    int prev2 = 0;
    int prev1 = 0;
    int curr = 1;

    if (n == 0){
        curr = 0;
    }

    for (int i = 1; i < n; i++){
        prev2 = prev1;
        prev1 = curr;
        curr = prev2 + prev1;
    }

    return curr;
}

/**
 *  add your comment
 */
int dpbu_fibonacci(int *f, int n) {
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++){
        f[i] = f[i-2] + f[i-1];
    }
    return f[n];
}

/**
 *  add your comment
 */
int dptd_fibonacci(int *f, int n) {
    if (n <= 1){
        f[n] = n;
        return f[n];
    }

    if (f[n] > 0){
        return f[n];
    }

    else {
        f[n] = dptd_fibonacci(f, n-2) + dptd_fibonacci(f, n-1);
        return f[n];
    }
}