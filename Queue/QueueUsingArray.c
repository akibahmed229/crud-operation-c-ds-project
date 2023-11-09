#include <stdio.h>
#include <stdlib.h>

#include "QueueUsingArray.h"

// Function to check if the QUEUE is full
int isFull(struct QUEUE *q) {
    if (q->rear_ind == q->size - 1) {
        return 1; // QUEUE is full
    }
    return 0; // QUEUE is not full
}

// Function to check if the QUEUE is empty
int isEmpty(struct QUEUE *q) {
    if (q->front_ind == q->rear_ind) {
        return 1; // QUEUE is empty
    }
    return 0; // QUEUE is not empty
}

// Function to enQUEUE (insert) an element into the queue
void enqueue(struct QUEUE *q, char *data) {
    if (isFull(q)) {
        printf("QUEUE is full\n");
        return;
    } else {
        q->rear_ind++;           // Move the rear index forward
        q->arr[q->rear_ind][100] = data; // Insert the data at the rear index
    }
}

// Function to deQUEUE (remove) an element from the queue
char * dequeue(struct QUEUE *q) {
    if (isEmpty(q)) {
        printf("QUEUE is empty\n");
        return NULL;
    } 
    q->front_ind++; // Move the front index forward
    return q->arr[q->front_ind][100]; // Return the data at the front index
}

// Function to print the elements in the QUEUE
void printqueue(struct QUEUE *q) {
    for (int i = q->front_ind + 1; i <= q->rear_ind; i++) {
        printf("%s ", q->arr[i][100]);
    }
    printf("\n");
}

