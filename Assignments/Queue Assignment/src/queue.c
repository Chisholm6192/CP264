/**
 * -------------------------------------
 * @file  queue.c
 * 
 * -------------------------------------
 * @author Ryan Chisholm, 169027577, chis7577@mylaurier.ca
 *
 * @version 2024-02-26
 *
 * ------------------------------------- */

#include <stdio.h>
#include "queue.h"

/* 
 * Enqueue a node into a queue
 * @param *qp - pointer to the queue 
 * @param NODE *np - pointer to the node.
*/
void enqueue(QUEUE *qp, NODE *np) {
  np->next = NULL;

  if(qp->front == NULL){ //if queue is empty, insert to front
    qp->front = np;
    qp->rear = qp->front;
  }
  else { //if queue is not empty, insert to rear 
    qp->rear->next = np;
    qp->rear = np;
  }
  qp->length += 1;
}  

/* 
 * Dequeue and return the pointer of the removed node. 
 * @param *qp - pointer to the queue 
*/
NODE *dequeue(QUEUE *qp) {
  if(qp->front != NULL){
    if(qp->front->next == NULL){ //if there is only one node in queue
      NODE *temp = qp->front;
      qp->front = NULL;
      qp->rear = NULL;
      free(temp);
    } 
    else { //there is more than one node in the queue
      NODE *temp = qp->front;
      qp->front = qp->front->next;
      temp->next = NULL;
      free(temp);
    }
    qp->length += 1;
  }
}

void clean_queue(QUEUE *qp) {
  clean(&(qp->front));
  qp->front = NULL;
  qp->rear = NULL;
  qp->length=0;
}