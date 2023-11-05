#include <stdio.h>
#include <stdlib.h>
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
    printf("\033[0;31m");  // Red text
    printf("\033[1m");     // Bold text
    printf("Error opening file\n");
    system("sleep 1");
    printf("\033[0;31m");  // Red text
  }

  // write to the FILE
  Node *getHead = returnHead();
  Node *temp = getHead;
  while (temp != NULL) {
    fprintf(fp, "%d %s %s %d\n", temp->empID, temp->name, temp->designation, temp->salary);
    temp = temp->next;
  };

  fclose(fp);

  freeMemory(); 
}

//  Create employee details
void create(){
#ifdef LINKLISTOPERATION_H

  int n;

  printf("Enter the number of employees: ");
  scanf("%d", &n);

  // create n nodes in the linked list 
  for (int i= 0; i<n; i++) {
    char name[20], designation[20];
    int empID, salary;

    printf("Enter employee details\n\n");
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

#else
  printf("\033[0;31m");  // Red text
  printf("\033[1m");     // Bold text
  printf("LinkListOperation.h not found\n");
  system("sleep 1");
  printf("\033[1m");     // Bold text
  printf("\033[0;32m");  // Green text
#endif
}



// Read employee details
void read(){
  FILE *fp;
  fp = fopen("employee.txt", "r");

  if (fp == NULL) {
    printf("\033[0;31m");  // Red text
    printf("\033[1m");     // Bold text
    printf("Error opening file\n");
    system("sleep 1"); 
    printf("\033[1m");     // Bold text
    printf("\033[0;32m");  // Green text
    return;
  }
 
  // store the employee details from the file
  int empID, salary;
  char name[20], designation[20];

  // read from the FILE 
  while (fscanf(fp, "%d %s %s %d", &empID, name, designation, &salary) != EOF) {
    printf("%d %s %s %d\n", empID, name, designation, salary);
  }

  fclose(fp);
}
// Update employee details
void update(){

}

// Delete employee details
void delete() {
  int rm_empID, line_count;

  printf("Enter the employee ID to delete: ");
  scanf("%d", &rm_empID);

  FILE *fp = fopen("employee.txt", "r");

  // Count the number of lines in the file
  line_count = 0;
  int empID, salary;
  char name[20], designation[20];
  char *found_emp;


  while (fscanf(fp, "%d %s %s %d", &empID, name, designation, &salary) != EOF) {
    if (empID == rm_empID) {
      found_emp = (char *)malloc(sizeof(char) * 100);
      sprintf(found_emp, "%d %s %s %d\n", empID, name, designation, salary);
    }
    
    line_count++;
  }

  rewind(fp);  // Reset the file pointer to the beginning

  struct QUEUE *q=(struct QUEUE *)malloc(sizeof(struct QUEUE));
  q->front_ind = q->rear_ind = -1;
  q->size = line_count;

  char str[line_count][100];  // An array to hold the lines

  // Read lines and enqueue them
  int i = 0;
  while (fgets(str[i], sizeof(str[i]), fp) != NULL) {
    // Now you have a line stored in str[i], you can enqueue it.
    enqueue(q, str[i]);
    i++;
  }
  fclose(fp);

  // now dequeue the lines and write to the file 
  fp = fopen("employee.txt", "w");

  printf("found employee %s \n", found_emp);
  char *line;
  for (int i = q->front_ind + 1; i <= q->rear_ind; i++) {
    line = dequeue(q);
     
    // if line match wiht found_emp then skip that line and write other lines to the FILE 
    if (strcmp(line, found_emp) == 0) {
      continue;
    }
    fputs(line, fp);
  }
  fclose(fp);
}



// Use system-specific commands to clear the terminal
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Linux and Unix-like systems
    #endif
}

int main()
{
  clearScreen();

  // Color codes for terminal ( ANSI escape codes )
  //  [ indicates the start of a command.
  //  0 is a parameter indicating a reset or default style.
  //  ; separates parameters.
  //  32 is the parameter for Green text.
  printf("\033[0;32m");  // Green text
  printf("\033[1m");     // Bold text
  printf("\033[40m");    // Black background

  // Main menu
  while (1) {
    printf("\033[40m");    // Black background
    int choice;
    
    printf("Choose an operation:\n");
    printf("1. Create\n");
    printf("2. Read\n");
    printf("3. Update\n");
    printf("4. Delete\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    clearScreen();
    switch (choice) {
      case 1:
        // create operation
        create();
        break;
      case 2:
        // read operation
        read();
        break;
      case 3:
        // update operation
        break;
      case 4:
        // delete operation
        delete();
        break; 
      case 5:
        // exit
        exit(0);
      default:
        printf("\033[0;31m");  // Red text
        printf("\033[1m");     // Bold text
        printf("Invalid choice\n");
        system("sleep 1");
        printf("\033[1m");     // Bold text
        printf("\033[0;32m");  // Green text

    }
  }
  printf("\033[0m");      // Reset to default colors

  return 0;
}
