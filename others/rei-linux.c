#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
// #include <conio.h>
#include <termios.h>
#include <unistd.h>

#define MAX_STUDENTS 5
#define MAX_NAME_LENGTH 50
#define MAX_FAMILY_NAME_LENGTH 50
#define MAX_COURSE_LENGTH 50

// Define the structure for a student record
struct Student {
    int id;
    char name[MAX_NAME_LENGTH];
    char familyName[MAX_FAMILY_NAME_LENGTH];
    char course[MAX_COURSE_LENGTH];
    int year;
    char gender;
};

// Function prototypes
void addStudent(struct Student students[], int *numStudents);
void displayStudents(const struct Student students[], int numStudents);
int searchStudent(const struct Student students[], int numStudents, int targetId);
void updateStudent(struct Student students[], int numStudents, int targetId);
void deleteStudent(struct Student students[], int *numStudents, int targetId);
void clearBuffer();

void loadStudents(struct Student students[], int *numStudents);
void saveStudents(const struct Student students[], int numStudents);

int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr(STDIN_FILENO, &oldattr);
    newattr = oldattr;
    newattr.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newattr);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldattr);
    return ch;
}


int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;
    char choice;
    int targetId;

    loadStudents(students, &numStudents);

    do {
        printf("\n1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        choice = getch();
        printf("\n");

        switch (choice) {
            case '1':
                addStudent(students, &numStudents);
                break;
            case '2':
                displayStudents(students, numStudents);
                break;
            case '3':
                printf("Enter student ID to search: ");
                scanf("%d", &targetId);
                clearBuffer();
                searchStudent(students, numStudents, targetId);
                break;
            case '4':
                printf("Enter student ID to update: ");
                scanf("%d", &targetId);
                clearBuffer();
                updateStudent(students, numStudents, targetId);
                break;
            case '5':
                printf("Enter student ID to delete: ");
                scanf("%d", &targetId);
                clearBuffer();
                deleteStudent(students, &numStudents, targetId);
                break;
            case '0':
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != '0');

    saveStudents(students, numStudents);

    return 0;
}

void addStudent(struct Student students[], int *numStudents) {
    if (*numStudents < MAX_STUDENTS) {
        int newId;
        printf("Enter student ID: ");
        scanf("%d", &newId);
        clearBuffer();

        // Check for duplicate ID
        for (int i = 0; i < *numStudents; i++) {
            if (students[i].id == newId) {
                printf("Student ID already exists. Cannot add student.\n");
                return;
            }
        }

        students[*numStudents].id = newId;

        printf("Enter student name: ");
        fgets(students[*numStudents].name, MAX_NAME_LENGTH, stdin);
        students[*numStudents].name[strcspn(students[*numStudents].name, "\n")] = 0;

        printf("Enter student family name: ");
        fgets(students[*numStudents].familyName, MAX_FAMILY_NAME_LENGTH, stdin);
        students[*numStudents].familyName[strcspn(students[*numStudents].familyName, "\n")] = 0;

        printf("Enter student course: ");
        fgets(students[*numStudents].course, MAX_COURSE_LENGTH, stdin);
        students[*numStudents].course[strcspn(students[*numStudents].course, "\n")] = 0;

        printf("Enter student year: ");
        scanf("%d", &students[*numStudents].year);
        clearBuffer();

        printf("Enter student gender (M/F): ");
        students[*numStudents].gender = toupper(getch());
        clearBuffer();

        (*numStudents)++;
        printf("Student added successfully!\n");
    } else {
        printf("Maximum number of students reached. Cannot add more.\n");
    }
}

void displayStudents(const struct Student students[], int numStudents) {
    if (numStudents > 0) {
        printf("\nStudent ID\tName\t\tFamily Name\tCourse\t\tYear\tGender\n");
        for (int i = 0; i < numStudents; i++) {
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t%c\n", students[i].id, students[i].name, students[i].familyName, students[i].course, students[i].year, students[i].gender);
        }
    } else {
        printf("No students to display.\n");
    }
}

int searchStudent(const struct Student students[], int numStudents, int targetId) {
    for (int i = 0; i < numStudents; i++) {
        if (students[i].id == targetId) {
            printf("Student found!\n");
            printf("Student ID\tName\t\tFamily Name\tCourse\t\tYear\tGender\n");
            printf("%d\t\t%s\t\t%s\t\t%s\t\t%d\t%c\n", students[i].id, students[i].name, students[i].familyName, students[i].course, students[i].year, students[i].gender);
            return i;
        }
    }

    printf("Student with ID %d not found.\n", targetId);
    return -1;
}

void updateStudent(struct Student students[], int numStudents, int targetId) {
    int index = searchStudent(students, numStudents, targetId);
    if (index != -1) {
        printf("Enter new student name: ");
        scanf("%s", students[index].name);

        printf("Enter new student family name: ");
        scanf("%s", students[index].familyName);

        printf("Enter new student course: ");
        scanf("%s", students[index].course);

        printf("Enter new student year: ");
        scanf("%d", &students[index].year);

        printf("Enter new student gender (M/F): ");
        clearBuffer();
        students[index].gender = toupper(getch());

        clearBuffer();

        printf("Student updated successfully!\n");
    } else {
        printf("Student with ID %d not found. Cannot update.\n", targetId);
    }
}

void deleteStudent(struct Student students[], int *numStudents, int targetId) {
    int index = -1;
    for (int i = 0; i < *numStudents; i++) {
        if (students[i].id == targetId) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        // Shift all elements after the found student to the left
        for (int i = index; i < *numStudents - 1; i++) {
            students[i] = students[i + 1];
        }

        (*numStudents)--;
        printf("Student deleted successfully!\n");
    } else {
        printf("Student with ID %d not found. Cannot delete.\n", targetId);
    }
}

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

void loadStudents(struct Student students[], int *numStudents) {
    FILE *file = fopen("students_management.txt", "r");
    if (file) {
        while (fscanf(file, "%d %s %s %s %d %c", &students[*numStudents].id, students[*numStudents].name, students[*numStudents].familyName, students[*numStudents].course, &students[*numStudents].year, &students[*numStudents].gender) == 6) {
            (*numStudents)++;
        }
        fclose(file);
    }
}

void saveStudents(const struct Student students[], int numStudents) {
    FILE *file = fopen("students_management.txt", "w");
    if (file) {
        for (int i = 0; i < numStudents; i++) {
            fprintf(file, "%d %s %s %s %d %c\n", students[i].id, students[i].name, students[i].familyName, students[i].course, students[i].year, students[i].gender);
        }
        fclose(file);
    }
}