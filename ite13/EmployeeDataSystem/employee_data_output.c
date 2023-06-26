#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VAL 100

typedef struct employee {
  char name[MAX_VAL];
  int age;
  char position[MAX_VAL];
  int salary;
  char address[MAX_VAL];
} Employee;

void salaryRequirement(Employee* emp, int number_of_employees) {
  printf("Employees with a salary greater than 10,000:\n");
  int placement = 1;
  for (int i = 0; i < number_of_employees; i++) {
    if (emp[i].salary > 10000) {
      printf("(%d) %s\n", placement++, emp[i].name);
    }
  }
  printf("\n");
}

void searchFunc(Employee* emp, int number_of_employees) {
  char searchInput[MAX_VAL];
  printf("Search name: ");
  scanf(" %[^\n]s", searchInput);

  searchInput[0] = toupper(searchInput[0]);

  int i = 0;
  bool showNotFound = true;

  if (strlen(searchInput) >= 3) {
    for (; i < number_of_employees; i++) {
      if (strstr(emp[i].name, searchInput) != NULL) {
        printf("\n-- Data Found --\n");
        printf("Name: %s\n", emp[i].name);
        printf("Age: %d\n", emp[i].age);
        printf("Position: %s\n", emp[i].position);
        printf("Salary: %d\n", emp[i].salary);
        printf("Address: %s\n", emp[i].address);
        showNotFound = false;
      }
    }
    if (showNotFound) {
      printf("-- Not Found --\n");
    }
  } else {
    printf("Minimum of three characters\n");
  }
  printf("\n");
}

void changeSalary(Employee* emp, int number_of_employees) {
  int newSalary = 5000;
  printf("Changing Salary to %d:\n", newSalary);
  for (int i = 0; i < number_of_employees; i++) {
    int oldSalary = emp[i].salary;
    emp[i].salary = newSalary;
    printf("%d --> %d\n", oldSalary, emp[i].salary);
  }
  printf("\n");
}

void uniquePosition(Employee* emp, int number_of_employees) {
  printf("Unique Positions:\n");

  int num_of_unique = 0;
  char displayedPositions[MAX_VAL][MAX_VAL] = {0};
  
  for (int i = 0; i < number_of_employees; i++) {
    bool isUnique = true;
    for (int j = 0; j < num_of_unique; j++) {
      if (strcmp(emp[i].position, displayedPositions[j]) == 0) {
        isUnique = false;
        break;
      }
    }
    if (isUnique) {
      printf("(%d) %s\n", ++num_of_unique, emp[i].position);
      strcpy(displayedPositions[num_of_unique - 1], emp[i].position);
    }
  }
  printf("\n");
}

void menu(Employee* emp, int number_of_employees) {
  int choice;
  printf("Enter what to do:\n");
  printf("----------------------------------\n");
  printf("(1) Display all employees with salary greater than 10,000\n");
  printf("(2) Search employee by name and display info\n");
  printf("(3) Change employee's salary\n");
  printf("(4) Display unique positions\n");
  printf("(5) Exit\n");
  printf("----------------------------------\n");
  printf("Input (1, 2, 3, 4, or 5) => ");
  scanf("%d", &choice);
  printf("\n\n");

  switch (choice) {
    case 1:
      system("clear");
      salaryRequirement(emp, number_of_employees);
      menu(emp, number_of_employees);
      break;
    case 2:
      system("clear");
      searchFunc(emp, number_of_employees);
      menu(emp, number_of_employees);
      break;
    case 3:
      system("clear");
      changeSalary(emp, number_of_employees);
      menu(emp, number_of_employees);
      break;
    case 4:
      system("clear");
      uniquePosition(emp, number_of_employees);
      menu(emp, number_of_employees);
      break;
    case 5:
      break;
    default:
      system("clear");
      printf("Invalid choice. Please try again.\n\n");
      menu(emp, number_of_employees);
      break;
  }
}

int main() {
  FILE* fpEmployee, * fpAge, * fpPosition, * fpSalary, * fpAddress;

  fpEmployee = fopen("Employee.txt", "r");
  fpAge = fopen("Age.txt", "r");
  fpPosition = fopen("Position.txt", "r");
  fpSalary = fopen("Salary.txt", "r");
  fpAddress = fopen("Address.txt", "r");

  if (fpEmployee == NULL || fpAge == NULL || fpPosition == NULL ||
      fpSalary == NULL || fpAddress == NULL) {
    printf("Failed to open file(s).\n");
    return 1;
  }

  int number_of_employees = 0;
  char line[MAX_VAL];

  while (fgets(line, sizeof(line), fpEmployee)) {
    number_of_employees++;
  }
  
  Employee* emp = malloc(number_of_employees * sizeof(Employee));
  
  rewind(fpEmployee);
  
  for (int i = 0; i < number_of_employees; i++) {
    fgets(line, sizeof(line), fpEmployee);
    line[strcspn(line, "\n")] = '\0';  // Remove newline character
    strcpy(emp[i].name, line);

    fgets(line, sizeof(line), fpAge);
    emp[i].age = atoi(line);

    fgets(line, sizeof(line), fpPosition);
    line[strcspn(line, "\n")] = '\0';  // Remove newline character
    strcpy(emp[i].position, line);

    fgets(line, sizeof(line), fpSalary);
    emp[i].salary = atoi(line);

    fgets(line, sizeof(line), fpAddress);
    line[strcspn(line, "\n")] = '\0';  // Remove newline character
    strcpy(emp[i].address, line);
  }

  fclose(fpEmployee);
  fclose(fpAge);
  fclose(fpPosition);
  fclose(fpSalary);
  fclose(fpAddress);

  menu(emp, number_of_employees);

  free(emp);

  return 0;
}
