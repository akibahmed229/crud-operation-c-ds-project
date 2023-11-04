#include <stdio.h>
#include <string.h>
#include "LinkList/LinkListOperation.h"
#include "Queue/Circular_queue_using_array.h"
#include "Stack/stack_using_array.h"

//  Function prototypes for CRUD operations on employee structure 

// write employee details to file
void write(){
  // Save the linked list to a file 
  FILE *fp;
  fp = fopen("employee.txt", "a");

  if (fp == NULL) {
    printf("Error opening file\n");
    exit(1);
  }

  // write to the FILE
  Node *getHead = returnHead();
  Node *temp = getHead;
  while (temp != NULL) {
    fprintf(fp, "%d %s %s %d\n", temp->empID, temp->name, temp->designation, temp->salary);
    temp = temp->next;
  };

  fclose(fp);
}

//  Create employee details
void create(){
  int n;

  printf("Enter the number of employees: ");
  scanf("%d", &n);

  // create n nodes in the linked list 
  for (int i= 0; i<n; i++) {
    char name[20], designation[20];
    int empID, salary;

    printf("Enter employee details\n");
    printf("Enter employee ID: ");
    scanf("%d", &empID);
    printf("Enter employee name: ");
    scanf("%s", name);
    printf("Enter employee designation: ");
    scanf("%s", designation);
    printf("Enter employee salary: ");
    scanf("%d", &salary);

    createSinglyLinkedList(name, designation, empID, salary, n);
  }
  // write to file 
  write();
  // print nodes in the linked list
  printList();
}


// Read employee details
void read(){

}
// Update employee details
void update(){

}
// Delete employee details
void delete(){

}

int main()
{

  // Main menu
  while (1) {
    int choice;
    
    printf("Choose an operation:\n");
    printf("1. Create\n");
    printf("2. Read\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        // create operation
        create();
        break;
      case 2:
        // read operation
        break;
      case 3:
        // update operation
        break;
      case 4:
        // delete operation
        break; 
      default:
        printf("Invalid choice\n");
    }
  }

  return 0;
}
