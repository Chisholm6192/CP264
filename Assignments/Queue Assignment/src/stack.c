/**
 * -------------------------------------
 * @file  stack.c
 * 
 * -------------------------------------
 *
 * @version 2024-02-26
 *
 * ------------------------------------- */ 

#include <stdio.h>
#include "stack.h"

/* 
 * Push a node into a linked list stack
 * @param STACK *sp - pointer to the stack 
 * @param NODE *np - pointer to the node.
*/
void push(STACK *sp, NODE *np) {
  np->next = sp->top;
  sp->top = np;
  sp->length += 1;
}

/* 
 * Pop and return the pointer of the removed top node
 * @param STACK *sp - pointer to the stack 
*/ 
NODE *pop(STACK *sp) {
  if(sp->top != NULL){ //if the stack is not empty
    NODE *temp = sp->top;
    sp->top = sp->top->next;

    temp->next = NULL; //remove pointer from old top
    free(temp); //free value from memory
    sp->length -= 1;
  }
}

void clean_stack(STACK *sp) {
  clean(&(sp->top));
  sp->top = NULL;
  sp->length=0;
}
