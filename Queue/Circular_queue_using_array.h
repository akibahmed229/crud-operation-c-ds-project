#ifndef CIRCULAR_QUEUE_USING_ARRAY_H // If CIRCULAR_QUEUE_USING_ARRAY_H is not defined
#define CIRCULAR_QUEUE_USING_ARRAY_H // Define CIRCULAR_QUEUE_USING_ARRAY_H

#include <stdio.h>
#include <stdlib.h>

// Define the structure for the circular queue
struct circular_queue {
    int size;
    int front_ind;
    int rear_ind;
    int *arr;
};

// Function to check if the circular queue is empty
int isEmpty(struct circular_queue *q) {
    if (q->front_ind == -1 && q->rear_ind == -1) {
        return 1; // Queue is empty
    }
    return 0; // Queue is not empty
}

// Function to check if the circular queue is full
int isFull(struct circular_queue *q) {
    if ((q->rear_ind + 1) % q->size == q->front_ind) {
        return 1; // Queue is full
    }
    return 0; // Queue is not full
}

// Function to enqueue (add) an element to the circular queue
void enqueue(struct circular_queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front_ind = q->rear_ind = 0; // Initialize front and rear indices for the first element
    } else {
        q->rear_ind = (q->rear_ind + 1) % q->size; // Update rear index in a circular manner
    }
    q->arr[q->rear_ind] = data; // Store data at the rear index
}

// Function to dequeue (remove) an element from the circular queue
int dequeue(struct circular_queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->arr[q->front_ind]; // Get data from the front index
    if (q->front_ind == q->rear_ind) {
        q->front_ind = q->rear_ind = -1; // Reset front and rear indices for the last element
    } else {
        q->front_ind = (q->front_ind + 1) % q->size; // Update front index in a circular manner
    }
    return data; // Return the dequeued data
}

// Function to print the elements in the circular queue
void printCircularQueue(struct circular_queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    int i = q->front_ind;
    do {
        printf("%d ", q->arr[i]); // Print data at the current index
        i = (i + 1) % q->size; // Move to the next index in a circular manner
    } while (i != (q->rear_ind + 1) % q->size); // Continue until reaching the rear index again
    printf("\n");
}


#endif // End of header file
