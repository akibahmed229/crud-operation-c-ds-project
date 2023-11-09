#ifndef QUEUE_USING_ARRAY_H // If QUEUE_USING_ARRAY_H is not defined
#define QUEUE_USING_ARRAY_H // Define QUEUE_USING_ARRAY_H


// Define a structure for the QUEUE
struct QUEUE {
    int size;       // Maximum size of the QUEUE
    int front_ind;  // Index of the front element
    int rear_ind;   // Index of the rear element
    char *arr[][100];       // Array to store QUEUE elements
};


int isFull(struct QUEUE *q);


int isEmpty(struct QUEUE *q);

void enqueue(struct QUEUE *q, char *data);

char * dequeue(struct QUEUE *q);

void printqueue(struct QUEUE *q);

#endif // End of header file
