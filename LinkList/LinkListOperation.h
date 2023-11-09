#ifndef LINKLISTOPERATION_H // If LINKLISTOPERATION_H is not defined   
#define LINKLISTOPERATION_H // Define LINKLISTOPERATION_H

void createSinglyLinkedList(char name[], char designation[], int empID, int salary);


void insertNodeAtBeginning(char name[], char designation[], int empID, int salary);

void insertNodeAtEnd(char name[], char designation[], int empID, int salary);


void insertNodeAtPosition(char name[], char designation[], int empID, int salary, int position);

void deleteNodeAtBeginning();

void deleteNodeAtEnd();

void deleteNodeAtPosition(int position);

void searchNode(int key);

void printList();

void freeMemory();

#endif // End of header file
