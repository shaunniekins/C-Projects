#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct StudentRecord {
    int idNumber;
    char name[50];
    char familyName[50];
    char course[50];
    char year[10];
    char gender[10];
};

int n = 0;
struct StudentRecord students[100];

void saveToFile() {
    FILE *file = fopen("student_records.txt", "w");

    if (file == NULL) {
        printf("Error opening file for writing\n");
        exit(1);
    }

    fprintf(file, "\nID NUMBER:\tNAME:\tFAMILY NAME:\tCOURSE:\tYEAR:\tGENDER:");
    for (int i = 0; i < n; i++) {
        fprintf(file, "\n%d\t\t%s\t%s\t\t%s\t\t%s\t\t%s", students[i].idNumber, students[i].name,
                students[i].familyName, students[i].course, students[i].year, students[i].gender);
    }

    fclose(file);
}

void loadFromFile() {
    FILE *file = fopen("student_records.txt", "r");

    if (file == NULL) {
        // File does not exist yet; it will be created when saving data.
        return;
    }

    while (fscanf(file, "%d%s%s%s%s%s", &students[n].idNumber, students[n].name, students[n].familyName,
                  students[n].course, students[n].year, students[n].gender) != EOF) {
        n++;
    }

    fclose(file);
}

int main() {
    loadFromFile();

    char ch;
    do {
        printf("\nA. Add");
        printf("\nB. Display");
        printf("\nS. Search");
        printf("\nU. Update");
        printf("\nE. Delete");
        printf("\nX. Exit");
        printf("\nEnter Option: ");
        scanf(" %c", &ch);
        switch (tolower(ch)) {
            case 'a':
                add();
                break;
            case 'b':
                display();
                break;
            case 's':
                search();
                break;
            case 'u':
                update();
                break;
            case 'e':
                delete();
                break;
            case 'x':
                saveToFile(); // Save data to file before exiting
                exit(0);
        }
    } while (ch != 'x');

    return 0;
}

int add() {
    printf("\nHow many students you want to add: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("\nStudent: %d", i + 1);
        printf("\nID Number: ");
        scanf("%d", &students[i].idNumber);
        printf("\nName: ");
        scanf("%s", students[i].name);
        printf("Family Name: ");
        scanf("%s", students[i].familyName);
        printf("Course: ");
        scanf("%s", students[i].course);
        printf("Year: ");
        scanf("%s", students[i].year);
        printf("Gender: ");
        scanf("%s", students[i].gender);
    }
    saveToFile();
}

int display() {
    printf("\nThe student records are:\n");
    printf("\nID NUMBER:\tNAME:\tFAMILY NAME:\tCOURSE:\tYEAR:\tGENDER:");
    for (int i = 0; i < n; i++)
        printf("\n%d\t\t%s\t%s\t\t%s\t\t%s\t\t%s", students[i].idNumber, students[i].name, students[i].familyName,
               students[i].course, students[i].year, students[i].gender);
}

int search() {
    int idNumber;
    printf("\nEnter the ID Number to be searched: ");
    scanf("%d", &idNumber);
    for (int i = 0; i < n; i++) {
        if (students[i].idNumber == idNumber) {
            printf("\nStudent Found!");
            printf("\nID NUMBER:\tNAME:\tFAMILY NAME:\tCOURSE:\tYEAR:\tGENDER:");
            printf("\n%d\t\t%s\t%s\t\t%s\t\t%s\t\t%s\n", students[i].idNumber, students[i].name, students[i].familyName,
                   students[i].course, students[i].year, students[i].gender);
            return i;
        }
    }
    printf("Student not found.\n");
    return -1;
}

int update() {
    int i, num;
    printf("\nEnter the ID Number to be updated: ");
    scanf("%d", &num);
    for (i = 0; i < n; i++) {
        if (students[i].idNumber == num) {
            printf("\nUpdated Name: ");
            scanf("%s", students[i].name);
            printf("Updated Family Name: ");
            scanf("%s", students[i].familyName);
            printf("Updated Course: ");
            scanf("%s", students[i].course);
            printf("Updated Year: ");
            scanf("%s", students[i].year);
            printf("Updated Gender: ");
            scanf("%s", students[i].gender);
            printf("\nStudent updated successfully!");
            saveToFile();
        }
    }
}

int delete() {
    int i, idNumber;
    printf("\nID Number to be deleted: ");
    scanf("%d", &idNumber);
    for (i = 0; i < n; i++) {
        if (students[i].idNumber == idNumber) {
            for (int j = i; j < n - 1; j++) {
                students[j] = students[j + 1];
            }
            n--;
            printf("\nStudent deleted successfully!");
            saveToFile();
        }
    }
    return 0;
}

