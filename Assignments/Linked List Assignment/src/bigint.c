/*--------------------------------------------------
 File:    bigint.c
 About:   BIGINT Doubly Linked List Data Structure
 Author:  Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 Version: 2024-02-17
 --------------------------------------------------
 */
 
#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
  BIGINT bn = {0};
  if (p == NULL) 
    return bn;
  else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
    return bn;
  }
  else if (*p == '0' && *(p+1) == '\0') {// just "0"
    dll_insert_end(&bn, new_node(*p -'0'));
    return bn;
  }  
  else { 
    while (*p) {
      if (*p >= '0' && *p <= '9' ){
        dll_insert_end(&bn, new_node(*p -'0'));
      } else {
        dll_clean(&bn);
        break;
      }
      p++;
    }
    return bn;
  }
}

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
    BIGINT sum = bigint(NULL);
    NODE *num1 = op1.end;
    NODE *num2 = op2.end;

    //carry, sum, and numeric variables a and b
    int carry = 0;
    int a, b, s;

    while(num1 != NULL || num2 != NULL){ //run until the end of both numbers has been reached
        a = 0;
        b = 0;

        if(num1 != NULL){ //if num1 end hasn't been reached
            a = num1->data;
            num1 = num1->prev;
        }
        if(num2 != NULL){ //if num2 end hasn't been reached
            b = num2->data;
            num2 = num2->prev;
        }
        s = a + b + carry; //get sum of numbers and carry value

        if(s >= 10){ //if sum requires a carry
            NODE *temp = (NODE*) malloc(sizeof(NODE));
            temp->data = s-10;
            carry = 1;
            dll_insert_start(&sum, temp); //insert new value to front of sum list
        }
        else { //sum is small enough to not need carry
            NODE *temp = (NODE*) malloc(sizeof(NODE));
            temp->data = s;
            carry = 0;
            dll_insert_start(&sum, temp);
        }
    }
    if(carry == 1){ //if there is a carry value
        NODE *temp = (NODE*) malloc(sizeof(NODE));
        temp->data = 1;
        dll_insert_start(&sum, temp);
    }
    
    return sum;
}

BIGINT bigint_fibonacci(int n) {
    //fibonacci terms 1 and 2 are 0 and 1 by default
    BIGINT f1 = bigint("0");
    BIGINT f2 = bigint("1");
    BIGINT temp = bigint(NULL);

    if(n == 0){
        return f1;
    }
    else if(n == 1){
        return f2;
    }
    else{
        for(int i = 2; i <= n; i++){
            temp = f2; //temporarly holds most recent value
            f2 = bigint_add(f1, f2); //sums two previous terms
            f1 = temp;
        }
        return f2;
    }
    dll_clean(&f2);
    dll_clean(&f1);
    free(&temp);
}