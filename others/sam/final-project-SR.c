#include <stdio.h>
#include <string.h>

struct StudentRecord {
    int idNumber;
    char name[50];
    char familyName[50];
    char course[50];
    char year[10];
    char gender[10];
};

void writeRecordToFile(const struct StudentRecord *record, const char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        printf("Error opening file %s for writing.\n", filename);
        return;
    }

    fprintf(file, "ID Number: %d\n", record->idNumber);
    fprintf(file, "Name: %s\n", record->name);
    fprintf(file, "Family Name: %s\n", record->familyName);
    fprintf(file, "Course: %s\n", record->course);
    fprintf(file, "Year: %s\n", record->year);
    fprintf(file, "Gender: %s\n", record->gender);
    fprintf(file, "\n");

    fclose(file);
}

void displayRecordsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s for reading.\n", filename);
        return;
    }
    printf("\nAll Student Records:\n");
    char buffer[100];
    int dataRead = 0; // flag to check if any data was read
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        printf("%s", buffer);
        dataRead = 1; // set flag to 1 if data was read
    }
    if (dataRead == 0) { // if no data was read, print 'No records'
        printf("No records\n");
    }
    fclose(file);
}

int searchRecordInFile(int idNumber, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file %s for reading.\n", filename);
        return 0;
    }

    char buffer[100];
    int currentIdNumber;
    int found = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        if (strstr(buffer, "ID Number:") != NULL && sscanf(buffer, "ID Number: %d", &currentIdNumber) == 1 && currentIdNumber == idNumber) {
            found = 1;
            printf("%s", buffer); // Print the ID number line
        } else if (found) {
            printf("%s", buffer); // Print the rest of the record
            if (strstr(buffer, "Gender:") != NULL) {
                break; // Stop printing after the Gender line
            }
        }
    }

    fclose(file);
    return found;
}

void updateRecordInFile(const struct StudentRecord *newRecord, int idNumber, const char *filename) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("student_data.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening files for updating.\n");
        return;
    }

    char line[100];
    int currentIdNumber;
    int skipLines = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "ID Number:") != NULL && sscanf(line, "ID Number: %d", &currentIdNumber) == 1 && currentIdNumber == idNumber) {
            skipLines = 6; // Skip the next 6 lines (including this one)
        }
        if (skipLines == 0) {
            fprintf(tempFile, "%s", line);
        } else {
            skipLines--;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("student_data.txt", filename);

    writeRecordToFile(newRecord, filename);
}

void deleteRecordFromFile(int idNumber, const char *filename) {
    FILE *file = fopen(filename, "r");
    FILE *tempFile = fopen("student_data.txt", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening files for deletion.\n");
        return;
    }

    char line[100];
    int currentIdNumber;
    int skipLines = 0;
    while (fgets(line, sizeof(line), file) != NULL) {
        if (strstr(line, "ID Number:") != NULL && sscanf(line, "ID Number: %d", &currentIdNumber) == 1 && currentIdNumber == idNumber) {
            skipLines = 6; // Skip the next 6 lines (including this one)
        }
        if (skipLines == 0) {
            fprintf(tempFile, "%s", line);
        } else {
            skipLines--;
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(filename);
    rename("student_data.txt", filename);
}

int main() {
    struct StudentRecord record;
    char filename[] = "StudentRecords.txt";
    int option;

    // Check if the file exists, and if not, create it
    FILE *fileCheck = fopen(filename, "r");
    if (fileCheck == NULL) {
        FILE *fileCreate = fopen(filename, "w");
        if (fileCreate != NULL) {
            fclose(fileCreate);
        } else {
            printf("Error creating file %s.\n", filename);
            return 1;
        }
    } else {
        fclose(fileCheck);
    }

    do {
        printf("\nOptions:\n");
        printf("1. Add\n");
        printf("2. Display\n");
        printf("3. Search\n");
        printf("4. Update\n");
        printf("5. Delete\n");
        printf("6. Exit\n");
        printf("Enter option: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("\nEnter ID Number: ");
                scanf("%d", &record.idNumber);

                if (searchRecordInFile(record.idNumber, filename)) {
                    printf("Record with the same ID number already exists. Please choose a different ID number.\n");
                    break;
                }

                printf("Enter Name: ");
                scanf("%s", record.name);
                printf("Enter Family Name: ");
                scanf("%s", record.familyName);
                printf("Enter Course: ");
                scanf("%s", record.course);
                printf("Enter Year: ");
                scanf("%s", record.year);
                printf("Enter Gender: ");
                scanf("%s", record.gender);

                writeRecordToFile(&record, filename);
                printf("Record added successfully.\n");
                break;

            case 2:
                displayRecordsFromFile(filename);
                break;

            case 3:
                printf("\nEnter ID Number to search: ");
                scanf("%d", &record.idNumber);
                if (searchRecordInFile(record.idNumber, filename)) {
                    printf("Record found.\n");
                } else {
                    printf("Record not found.\n");
                }
                break;

            case 4:
                printf("\nEnter ID Number to update: ");
                scanf("%d", &record.idNumber);

                if (!searchRecordInFile(record.idNumber, filename)) {
                    printf("Record not found. Cannot update.\n");
                    break;
                }

                printf("Enter updated Name: ");
                scanf("%s", record.name);
                printf("Enter updated Family Name: ");
                scanf("%s", record.familyName);
                printf("Enter updated Course: ");
                scanf("%s", record.course);
                printf("Enter updated Year: ");
                scanf("%s", record.year);
                printf("Enter updated Gender: ");
                scanf("%s", record.gender);

                updateRecordInFile(&record, record.idNumber, filename);
                printf("Record updated successfully.\n");
                break;

            case 5:
                printf("\nEnter ID Number to delete: ");
                scanf("%d", &record.idNumber);

                if (!searchRecordInFile(record.idNumber, filename)) {
                    printf("Record not found. Cannot delete.\n");
                    break;
                }

                deleteRecordFromFile(record.idNumber, filename);
                printf("Record deleted successfully.\n");
                break;

            case 6:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid option. Please choose a valid option.\n");
        }

    } while (option != 6);

    return 0;
}
