#include <stdio.h>
#include <string.h>

typedef struct address {
    char country[100];
    char city[50];
    char barangay[50];
    char street[50];
} Address;

typedef struct employee {
    char first_name[50];
    char middle_initial[50];
    char last_name[50];
    int age;
    char position[50];
    int salary;
    Address address1;
} Employee;

#define MAX_EMPLOYEES 100
#define FILE_EMPLOYEE "Employee.txt"
#define FILE_AGE "Age.txt"
#define FILE_POSITION "Position.txt"
#define FILE_SALARY "Salary.txt"
#define FILE_ADDRESS "Address.txt"

void readEmployeeData(Employee* employee);
void writeEmployeeDataToFile(Employee* employee, int numEmployees);

int main() {
    FILE *fpEmployee, *fpAge, *fpPosition, *fpSalary, *fpAddress;

    fpEmployee = fopen(FILE_EMPLOYEE, "a");
    fpAge = fopen(FILE_AGE, "a");
    fpPosition = fopen(FILE_POSITION, "a");
    fpSalary = fopen(FILE_SALARY, "a");
    fpAddress = fopen(FILE_ADDRESS, "a");

    if (fpEmployee == NULL || fpAge == NULL || fpPosition == NULL || fpSalary == NULL || fpAddress == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    int numEmployees;

    printf("Enter the number of persons: ");
    scanf("%d", &numEmployees);

    Employee employees[MAX_EMPLOYEES];

    for (int i = 0; i < numEmployees; i++) {
        printf("Enter details for Employee %d:\n", i + 1);
        readEmployeeData(&employees[i]);
    }

    writeEmployeeDataToFile(employees, numEmployees);

    fclose(fpEmployee);
    fclose(fpAge);
    fclose(fpPosition);
    fclose(fpSalary);
    fclose(fpAddress);

    return 0;
}

void readEmployeeData(Employee* employee) {
    printf("First Name: ");
    scanf(" %[^\n]%*c", employee->first_name);
    printf("Middle Initial: ");
    scanf(" %[^\n]%*c", employee->middle_initial);
    printf("Last Name: ");
    scanf(" %[^\n]%*c", employee->last_name);
    printf("Age: ");
    scanf("%d", &employee->age);
    printf("Position: ");
    scanf(" %[^\n]%*c", employee->position);
    printf("Salary: ");
    scanf("%d", &employee->salary);
    printf("Country of Origin: ");
    scanf(" %[^\n]%*c", employee->address1.country);
    printf("City: ");
    scanf(" %[^\n]%*c", employee->address1.city);
    printf("Barangay: ");
    scanf(" %[^\n]%*c", employee->address1.barangay);
    printf("Street: ");
    scanf(" %[^\n]%*c", employee->address1.street);
}

void writeEmployeeDataToFile(Employee* employee, int numEmployees) {
    FILE* fpEmployee = fopen(FILE_EMPLOYEE, "a");
    FILE* fpAge = fopen(FILE_AGE, "a");
    FILE* fpPosition = fopen(FILE_POSITION, "a");
    FILE* fpSalary = fopen(FILE_SALARY, "a");
    FILE* fpAddress = fopen(FILE_ADDRESS, "a");

    if (fpEmployee == NULL || fpAge == NULL || fpPosition == NULL || fpSalary == NULL || fpAddress == NULL) {
        printf("Error opening files for writing.\n");
        return;
    }

    for (int i = 0; i < numEmployees; i++) {
        fprintf(fpEmployee, "%s %s. %s\n", employee[i].first_name, employee[i].middle_initial, employee[i].last_name);
        fprintf(fpAge, "%d\n", employee[i].age);
        fprintf(fpPosition, "%s\n", employee[i].position);
        fprintf(fpSalary, "%d\n", employee[i].salary);
        fprintf(fpAddress, "%s %s, %s City, %s\n", employee[i].address1.street, employee[i].address1.barangay, employee[i].address1.city, employee[i].address1.country);
    }

    fclose(fpEmployee);
    fclose(fpAge);
    fclose(fpPosition);
    fclose(fpSalary);
    fclose(fpAddress);

    printf("\n- Files inserted successfully. -\n");
}
