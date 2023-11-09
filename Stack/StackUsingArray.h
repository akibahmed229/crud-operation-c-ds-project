#ifndef STACK_USING_ARRAY_H  // If STACK_USING_ARRAY_H is not defined
#define STACK_USING_ARRAY_H  // Define STACK_USING_ARRAY_H

// Define a structure for the stack
struct stack {
  int size;    // Size of the stack
  int top;     // Index of the top element in the stack
  int *arr;    // Pointer to an integer array to store stack elements
};

// Function prototypes

int is_Empty(struct stack *ptr);

int is_Full(struct stack *ptr);

void push(struct stack *ptr, int val);

int pop(struct stack *ptr);

int peek(struct stack *ptr, int pos);

int stackTop(struct stack *ptr);

int stackBottom(struct stack *ptr);

void display(struct stack *sp);

#endif  // End of header file
