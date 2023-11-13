#ifndef LINKLISTOPERATION_H // If LINKLISTOPERATION_H is not defined   
#define LINKLISTOPERATION_H // Define LINKLISTOPERATION_H

// Define the structure for the linked list of employees
struct node
{
  char name[20];
  char designation[20];
  int empID;
  int salary;
  struct node *next; // Pointer to the next node
}; 

typedef struct node Node; // Define an alias "Node" for "struct node"
 

// Function prototypes

void createSinglyLinkedList(char * name, char * designation, int empID, int salary);

void insertNodeAtBeginning(char * name, char * designation, int empID, int salary);

void insertNodeAtEnd(char * name, char * designation, int empID, int salary);

void insertNodeAtPosition(char * name, char * designation, int empID, int salary, int position);

void deleteNodeAtBeginning();

void deleteNodeAtEnd();

void deleteNodeAtPosition(int position);

void searchNode(int key);

void printList();

void freeMemory();

Node * returnHead();

#endif // End of header file
