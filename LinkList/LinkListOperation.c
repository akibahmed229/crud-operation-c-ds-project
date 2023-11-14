#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkListOperation.h"

Node *head;  // Define the variable in one source file

// Function to create a singly linked list with a single employee node
void createSinglyLinkedList(char *name, char *designation, int empID, int salary){
  Node *newNode;

  // Allocate memory for the new node
  newNode = (Node *)malloc(sizeof(Node));

  strcpy(newNode->name, name);
  strcpy(newNode->designation, designation);
  newNode->empID = empID;
  newNode->salary = salary;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode; // If the linked list is empty, set the head to the new node
  } else {
      Node *temp = head;
      while (temp->next != NULL) {
        temp = temp->next;
      }
      temp->next = newNode; // Connect the last node to the new node   
    }
  }

// Function to insert a new node at the beginning of the linked list
void insertNodeAtBeginning(char * name, char * designation, int empID, int salary){
  // Allocate memory for the new node
  Node *newNode= (Node *) malloc(sizeof(Node));

  strcpy(newNode->name, name);
  strcpy(newNode->designation, designation);
  newNode->empID = empID;
  newNode->salary = salary;
  newNode->next = head;      // Point the new node to the current head
  head = newNode;            // Update the head to the new node
}

// Function to insert a new node at the end of the linked list
void insertNodeAtEnd(char * name, char * designation, int empID, int salary){
  Node *newNode, *temp;

  // Allocate memory for the new node
  newNode = (Node *) malloc(sizeof(Node));

  strcpy(newNode->name, name);
  strcpy(newNode->designation, designation);
  newNode->empID = empID;
  newNode->salary = salary;
  newNode->next = NULL;     // Initialize the next pointer of the new node

  temp = head;

  while (temp->next != NULL) {
    temp = temp->next;       // Traverse to the last node
  }

  temp->next = newNode;     // Connect the last node to the new node
}

// Function to insert a new node at a specified position in the linked list
void insertNodeAtPosition(char *name, char * designation, int empID, int salary, int position){
  Node *newNode, *temp;

  // Allocate memory for the new node
  newNode = (Node *) malloc(sizeof(Node));

  strcpy(newNode->name, name);
  strcpy(newNode->designation, designation);
  newNode->empID = empID;
  newNode->salary = salary;
  newNode->next = NULL;     // Initialize the next pointer of the new node

  temp = head;

  for(int i=0; i<position-1; i++){
    if(temp->next != NULL){
      temp = temp->next;     // Traverse to the node before the specified position
    }
  }

  newNode->next = temp->next;  // Connect the new node to the node after the specified position
  temp->next = newNode;        // Connect the node before the specified position to the new node
}

// Function to delete the first node in the linked list
void deleteNodeAtBeginning(){
  Node *temp;

  temp = head;
  head = head->next; // Update the head to the next node
  free(temp);        // Free the memory of the deleted node
}

// Function to delete the last node in the linked list
void deleteNodeAtEnd(){
  Node *temp, *prevNode;

  temp = head;

  while(temp->next != NULL){
    prevNode = temp;
    temp = temp->next; // Traverse to the last node
  }

  if(temp == head){
    head = NULL;      // If there was only one node, set the head to NULL
  } else {
    prevNode->next = NULL; // Connect the node before the last node to NULL
  }

  free(temp);            // Free the memory of the deleted node
}

// Function to delete a node at a specified position in the linked list
void deleteNodeAtPosition(int position){
  Node *temp, *prevNode;

  temp = head;

  for(int i=0; i<position-1; i++){
    if(temp->next != NULL){
      prevNode = temp;
      temp = temp->next; // Traverse to the node before the specified position
    }
  }

  prevNode->next = temp->next; // Connect the node before the specified position to the node after it
  free(temp);                  // Free the memory of the deleted node
}

// Function to search for a node with a specific key in the linked list
void searchNode(int key){
  Node *temp;

  temp = head; // Start from the head node

  while(temp != NULL){
    if(temp->empID == key){
      printf("Key found\n");
      break;
    }
    temp = temp->next; // Traverse to the next node
  }

  if(temp == NULL){
    printf("Key not found\n");
  }
}


// Function to print the elements of the linked list
void printList(){
  while (head != NULL) {
    printf("Name: %s, Designation: %s, Employee ID: %d, Salary: %d\n", head->name, head->designation, head->empID, head->salary);
    head = head->next;
  }
  printf("\n");
}

// Function to free the memory allocated for the linked list 
void freeMemory(){
  Node *temp;

  while (head != NULL) {
    temp = head;
    head = head->next;
    free(temp);
  }
}

Node * returnHead(){
  return head;
}
