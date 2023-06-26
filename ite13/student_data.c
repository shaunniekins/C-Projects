/**
A simple program that allows users to insert student information such as roll number, name, department, course, and year of joining. Users can then search for students based on the year of joining and display the corresponding student details. The program provides a menu-driven interface for user interaction.
**/

#include <stdio.h>
#include <stdlib.h>

struct student {
    int roll_num;
    char name[50];
    char dept[50];
    char course[50];
    int year_join;
};

void callName(struct student *s, int total_students, int year_search) {
    int found = 0; // Flag to check if any students are found in the searched year

    for (int i = 0; i < total_students; i++) {
        if (s[i].year_join == year_search) {
            if (!found) {
                printf("\n%20s %20s %20s %20s %20s\n", "Roll Number", "Name", "Department", "Course", "Year Joined");
                found = 1;
            }
            printf("%20d %20s %20s %20s %20d\n", s[i].roll_num, s[i].name, s[i].dept, s[i].course, s[i].year_join);
        }
    }

    if (!found) {
        printf("No data for the year %d.\n", year_search);
    }
}

int main() {
    int total_students = 0;
    struct student *s = NULL;

    int choice;
    system("clear");
    do {
        printf("\nMenu:\n");
        printf("1. Insert student\n");
        printf("2. Search by year of join\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                system("clear");
                printf("Enter the total number of students to insert: ");
                scanf("%d", &total_students);

                s = (struct student*)malloc(total_students * sizeof(struct student));
                if (s == NULL) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }

                for (int i = 0; i < total_students; i++) {
                    printf("\nEnter roll number: ");
                    scanf("%d", &(s[i].roll_num));
                    printf("Enter name: ");
                    scanf("%s", s[i].name);
                    printf("Enter department: ");
                    scanf("%s", s[i].dept);
                    printf("Enter course: ");
                    scanf("%s", s[i].course);
                    printf("Enter year joined: ");
                    scanf("%d", &(s[i].year_join));
                }
                system("clear");
                break;
            }
            case 2: {
                system("clear");
                if (total_students == 0) {
                    printf("No students added yet.\n");
                } else {
                    int year_search;
                    printf("Enter the year of join to search: ");
                    scanf("%d", &year_search);
                    callName(s, total_students, year_search);
                }
                break;
            }
            case 3:
                system("clear");
                printf("Exiting program.\n");
                break;
            default:
                system("clear");
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    free(s);

    return 0;
}
