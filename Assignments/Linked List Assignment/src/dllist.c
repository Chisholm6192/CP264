/*--------------------------------------------------
 File:    dllist.c
 About:   Doubly Linked List Data Structure
 Author:  Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 Version: 2024-02-17
 --------------------------------------------------
 */
 
#include <stdio.h>
#include <stdlib.h> 
#include "dllist.h"

NODE *new_node(char data) {
    NODE *node = (NODE*) malloc(sizeof(NODE));
    node->data = data;
    return node;
}

void dll_insert_start(DLL *dllp, NODE *np) {
    if(dllp->start == NULL){ //list is empty
        np->prev = NULL;
        np->next = NULL;
        dllp->start = np;
        dllp->end = np;
    }
    else { //list is not empty
        np->prev = NULL;
        np->next = dllp->start;
        dllp->start->prev = np;
        dllp->start = np;

    }
    dllp->length += 1;
}

void dll_insert_end(DLL *dllp, NODE *np) {
    if(dllp->start == NULL){ //if list is empty
        np->prev = NULL;
        np->next = NULL;
        dllp->start = np;
        dllp->end = np;
    }
    else { //list is not empty
        np->next = NULL;
        np->prev = dllp->end;
        dllp->end->next = np;
        dllp->end = np;
    }
    dllp->length += 1;
}

void dll_delete_start(DLL *dllp) {
    if(dllp->start != NULL){
        if(dllp->start == dllp->end){
            NODE *temp = dllp->start;
            dllp->start = NULL;
            dllp->end = NULL;
            
            free(temp);
        }
        else {
            NODE *temp = dllp->start;
            dllp->start = dllp->start->next;
            dllp->start->prev = NULL;
            temp->next = NULL;

            free(temp);
        }
        dllp->length -= 1;
    }
}

void dll_delete_end(DLL *dllp) {
    if(dllp->start != NULL){
        if(dllp->start == dllp->end){ //if front and rear nodes are the same, there is only one node in list
            NODE *temp = dllp->start;
            dllp->start = NULL;
            dllp->end = NULL;

            free(temp);
        }
        else {
            NODE *temp = dllp->end;
            dllp->end = dllp->end->prev;
            dllp->end->next = NULL;
            temp->prev = NULL;

            free(temp);
        }
        dllp->length -= 1;
    } 
}

void dll_clean(DLL *dllp) {
    NODE *node = dllp->start;
    NODE *temp = NULL;

    while(node != NULL){
        temp = node;
        node = node->next;
        free(temp);
    }
    dllp->start = NULL;
    dllp->end = NULL;
    dllp->length = 0;
}