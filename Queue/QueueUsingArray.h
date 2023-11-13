#ifndef QUEUE_USING_ARRAY_H // If QUEUE_USING_ARRAY_H is not defined
#define QUEUE_USING_ARRAY_H // Define QUEUE_USING_ARRAY_H


// Define a structure for the QUEUE
struct queue {
    int size;       // Maximum size of the QUEUE
    int front_ind;  // Index of the front element
    int rear_ind;   // Index of the rear element
    char *arr[100];       // Array to store QUEUE elements
};

typedef struct queue Queue; // Define an alias "Queue" for "struct QUEUE"

// Function prototypes

int isFull(Queue *q);

int isEmpty(Queue *q);

void enqueue(Queue *q, char *data);

char * dequeue(Queue *q);

void printqueue(Queue *q);

#endif // End of header file
