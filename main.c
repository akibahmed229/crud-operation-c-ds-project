#include <bits/types/FILE.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkList/LinkListOperation.c"
#include "Queue/QueueUsingArray.c"
#include "Stack/StackUsingArray.c"

// Function to delay the execution of the program
void delay(int a)
{
    int add, time, i;

    time = a * 1000000; // Converting into micro seconds 
    for (i = 0; i < time; i++) 
    {
        add *= i;
        add++;
        add++;
    }
}

// Use system-specific commands to clear the terminal
void clearScreen() {
    #ifdef _WIN32
        system("cls");  // For Windows
    #else
        system("clear");  // For Linux and Unix-like systems
    #endif
}

// Function to display the welcome screen
void fordelay()
{
    int i;
    printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t");
    for (i = 0; i < 3; i++)
    {
        printf("* ");
        delay(500); // Delay for 500 milliseconds  
    }
    printf("\n\n\n");
}

// Function to prompt the user for continuation
int askToContinue() {
    char choice;
    printf("Do you want to continue? (y/n): ");
    scanf(" %c", &choice);  // Notice the space before %c to consume the newline character from previous input

    if (choice == 'y' || choice == 'Y') {
        return 1;  // User wants to continue
    } else {
        exit(0);  // User chose to exit
    }
}

// Show error message
void showError(char *message) {
    printf("\033[0;31m");  // Red text
    printf("\033[1m");     // Bold text
    printf("%s\n", message);
    delay(100);
    printf("\033[1m");     // Bold text
    printf("\033[0;32m");  // Green text
}

//  Function prototypes for CRUD operations on employee structure 
//  Create employee details & save to file
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

    createSinglyLinkedList(name, designation, empID, salary); // Add employees to the linked list
  }

  // Save the linked list to a file 
  FILE *fp;
  fp = fopen("employee.txt", "a");

  // check if the file exists
  if (fp == NULL) {
    showError("Error opening file");
  }

  // write to the FILE
  Node *getHead = returnHead();
  Node *temp = getHead;
  while (temp != NULL) {
    fprintf(fp, "%d %s %s %d\n", temp->empID, temp->name, temp->designation, temp->salary); // Write the employee details to the file
    temp = temp->next;
  };

  fclose(fp);
  freeMemory(); 
#else
  showError("LinkListOperation.h file not found");
#endif
}

// Read employee details
void read() {
    // Read the employee details from the file
    FILE *fp;
    fp = fopen("employee.txt", "r");

    // check if the file exists
    if (fp == NULL) {
        showError("Error opening file");
    }

    // store the employee details from the file
    int empID, salary;
    char name[20], designation[20];

    // Printing column headers
    printf("%-20s%-20s%-20s%-20s\n", "Employee ID", "Name", "Designation", "Salary");
    printf("%-20s%-20s%-20s%-20s\n", "-----------", "----", "-----------", "------");

    // read from the FILE 
    while (fscanf(fp, "%d %s %s %d", &empID, name, designation, &salary) != EOF) {
        // Printing formatted data
        printf("%-20d%-20s%-20s%-20d\n", empID, name, designation, salary);
    }
    printf("\n\n\n\n");

    fclose(fp);
}

// Update employee details
void update() {
#ifdef LINKLISTOPERATION_H
    int search_empID;
    printf("Enter the employee ID to update: ");
    scanf("%d", &search_empID);

    // Read the employee details from the file
    FILE *fp;
    fp = fopen("employee.txt", "r");

    // store the employee details from the file
    int empID, salary;
    char name[20], designation[20];

    while (fscanf(fp, "%d %s %s %d", &empID, name, designation, &salary) != EOF) {
        createSinglyLinkedList(name, designation, empID, salary); // Add employees to the linked list
    }

    fclose(fp);

    // Update the employee details
    int new_empID, new_salary;
    char new_name[20], new_designation[20];

    printf("Enter the new employee details\n\n");
    printf("Enter employee ID: ");
    scanf("%d", &new_empID);
    printf("Enter employee name: ");
    scanf("%s", new_name);
    printf("Enter employee designation: ");
    scanf("%s", new_designation);
    printf("Enter employee salary: ");
    scanf("%d", &new_salary);

    // Update the employee details in the linked list
    Node *current = returnHead();

    while (current != NULL) {
        if (current->empID == search_empID) {
            current->empID = new_empID;
            strcpy(current->name, new_name);
            strcpy(current->designation, new_designation);
            current->salary = new_salary;

            printf("Employee details updated successfully\n");
            break;
        }
        current = current->next;
    }

    // Write the updated employee details back to the file
    fp = fopen("employee.txt", "w");
    current = returnHead();

    while (current != NULL) {
        fprintf(fp, "%d %s %s %d\n", current->empID, current->name, current->designation, current->salary);
        current = current->next;
    }
  
    fclose(fp);
    freeMemory();
#else
    showError("LinkListOperation.h file not found");
#endif
}

// Delete employee details
void delete() {
#ifdef QUEUE_USING_ARRAY_H
    int rm_empID, line_count;

    printf("Enter the employee ID to delete: ");
    scanf("%d", &rm_empID);

    // Read the employee details from the file
    FILE *fp = fopen("employee.txt", "r");

    // Count the number of lines in the file
    line_count = 0;
    int empID, salary;
    char name[20], designation[20];
    char found_emp[100]; // Use a char array, not a pointer

    while (fscanf(fp, "%d %s %s %d", &empID, name, designation, &salary) != EOF) {
        if (empID == rm_empID) {
            sprintf(found_emp, "%d %s %s %d\n", empID, name, designation, salary); // Store the line to be deleted
        }

        line_count++;
    }

    rewind(fp);  // Reset the file pointer to the beginning

    // Create a queue to store the lines
    Queue *q = (Queue *)malloc(sizeof( Queue ));
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
    char line[100]; // Use a char array, not a pointer
    for (int i = q->front_ind + 1; i <= q->rear_ind; i++) {
        strcpy(line, dequeue(q));

        // if line match with found_emp then skip that line and write other lines to the FILE
        if (strcmp(line, found_emp) == 0) {
            continue;
        }
        fputs(line, fp);
    }
    
    free(q);
    fclose(fp);
#else
    showError("QueueUsingArray.h file not found");
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
  
  fordelay();

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
        printf("\n| ==============================CREATE YOUR ACCOUNT============================== |\n\n");
        create();
        askToContinue();
        break;
      case 2:
        // read operation
        printf("\n| ===============================READ YOUR ACCOUNT=============================== |\n\n");
        read();
        askToContinue();
        break;
      case 3:
        // update operation
        printf("\n| ==============================UPDATE YOUR ACCOUNT============================== |\n\n");
        update();
        askToContinue();
        break;
      case 4:
        // delete operation
        printf("\n| ==============================DELETE YOUR ACCOUNT============================== |\n\n");
        delete();
        askToContinue();
        break; 
      case 5:
        // exit
        exit(0);
      default:
      showError("\nInvalid choice");
    }
  }
  printf("\033[0m");      // Reset to default colors

  return 0;
}
