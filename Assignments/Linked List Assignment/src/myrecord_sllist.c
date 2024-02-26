/*--------------------------------------------------
 File:    myrecord_sllist.c
 About:   Singly Linked List Data Structure
 Author:  Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 Version: 2024-02-17
 --------------------------------------------------
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myrecord_sllist.h"


NODE *sll_search(SLL *sllp, char *name) {
    NODE *np = sllp->start;

    while(np != NULL){
        if(strcmp(np->data.name, name) == 0){ //names match
            break;
        }
        else {
            np = np->next;
        }
    }
    return np;
}

void sll_insert(SLL *sllp, char *name, float score) {
    //new node for insertion
    NODE *node = (NODE*) malloc(sizeof(NODE));
    strcpy(node->data.name, name);
    node->data.score = score;
    node->next = NULL;

    if (sllp->start == NULL){ //list is empty, so insert at front
        sllp->start = node;
        sllp->start->next = NULL;
    }
    else { //list is not empty
        //create new nodes for traversal of list
        NODE *prev = NULL;
        NODE *current = sllp->start;
        
        while (current != NULL && strcmp(current->data.name, name) < 0){ //run until a node with greater name is found, or end of list is reached
            prev = current;
            current = current->next;
        }
        if(prev == NULL){ //insertion spot found at front of list
            sllp->start = node;
            node->next = current;
        }
        else if(current == NULL){ //list end reached, so insert node to end
            prev->next = node;
        }
        else { //insert new node between previous and current nodes
            prev->next = node;
            node->next = current;
        }
    }
    sllp->length += 1; //increase length of list
}

int sll_delete(SLL *sllp, char *name) {
    if(sllp->start != NULL){ //if list is not empty
        NODE *prev = NULL;
        NODE *current = sllp->start;

        while (strcmp(current->data.name, name) != 0 && current != NULL){ //run until matching key is found, or list end is reached
            prev = current;
            current = current->next;
        }
        if (current != NULL){ //end of list was not reached, therefore matching key was found
            if(prev == NULL){ //matching key is found at front of list
                NODE *temp = sllp->start;
                sllp->start = sllp->start->next;
                temp->next = NULL;

                free(temp);
            }
            else if(current->next == NULL){ //matching key is found at end of list
                NODE *temp = current;
                prev->next = NULL;

                free(temp);
            }
            else { //matching key found anywhere else in list
                NODE *temp = current;
                prev->next = current->next;

                free(temp);
            }
            sllp->length -= 1; //decreae length of list
        }
    }
}

void sll_clean(SLL *sllp) {
    NODE *temp, *ptr = sllp->start;
    while (ptr != NULL) {
        temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    sllp->start = NULL;
    sllp->length = 0;
}