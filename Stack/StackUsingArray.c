#include <stdio.h>
#include <stdlib.h>

#include "StackUsingArray.h"

// Function to check if the stack is empty
int is_Empty(struct stack *ptr){
  if (ptr->top <= -1){
    return 1;  // Return 1 if the stack is empty
  }
  return 0;    // Return 0 if the stack is not empty
}

// Function to check if the stack is full
int is_Full(struct stack *ptr){
  if (ptr->top >= ptr->size-1){ 
    return 1;  // Return 1 if the stack is full
  }
  return 0;    // Return 0 if the stack is not full
}

// Function to push an element onto the stack
void push(struct stack *ptr, int val){
  if(is_Full(ptr)){
    printf("Stack Overflow\n"); // Print an error message if the stack is full
    return;
  }
  ptr->top++;          // Increment the top index
  ptr->arr[ptr->top] = val; // Place the value onto the stack
}

// Function to pop an element from the stack
int pop(struct stack *ptr){
  if(is_Empty(ptr)){
    printf("Stack Underflow\n"); // Print an error message if the stack is empty
    return -1;
  }
  int val = ptr->arr[ptr->top]; // Get the top element
  ptr->top--;                  // Decrement the top index
  return val;                   // Return the popped value
}

// Function to peek at an element in the stack at a specific position
int peek(struct stack *ptr, int pos){
  if(ptr->top - pos + 1 < 0){
    printf("Not a valid position for the stack\n"); // Print an error message for an invalid position
    return -1;
  }
  return ptr->arr[ptr->top - pos + 1]; // Return the value at the specified position
}

// Function to return the top element in the Stack
int stackTop(struct stack *ptr){
  return ptr->arr[ptr->top]; // Return the top elements
}

// Function to return the bottom element in the stack
int stackBottom(struct stack *ptr){
  return ptr->arr[0]; // Return the bottom element
}

// Function to display the values in the Stack
void display(struct stack *sp){
  // Print values from the stack
  for (int j = 1; j <= sp->top + 1; j++){
    printf("The value at position %d is %d\n", j, peek(sp, j));
  }
}
