/**
A simple student management system for a classroom. It allows users to input data for students, display the student data, search for students by last name, save the data to a file, and show the ranking of students based on their scores. The program presents a menu-based interface for users to navigate through these options.
**/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define MAX_LEN 50

typedef struct tasks {
  int quizzes[5];
  int prelim;
  int midterm;
  int final;
} Tasks;

typedef struct classroom {
  int id;
  char first_name[MAX_LEN];
  char middle_name[MAX_LEN];
  char last_name[MAX_LEN];
  int age;
  char contact_num[MAX_LEN];
  Tasks task;
} Classroom;

void input_data(Classroom *cl, int maxStud);
void display_data(Classroom *cl);
void search_lastName(Classroom *cl, int maxStud);
void saveFile(Classroom *cl, int maxStud);
void showRank(Classroom *cl, int maxStud);
void menu(Classroom *cl, int maxStud);

void input_data(Classroom *cl, int maxStud) {
  printf("-- ADD STUDENTS' DATA --\n\n");
  printf("Enter first name: ");
  scanf(" %[^\n]s", cl->first_name);
  printf("Enter middle name: ");
  scanf(" %[^\n]s", cl->middle_name);
  printf("Enter last name: ");
  scanf(" %[^\n]s", cl->last_name);
  printf("Enter age: ");
  scanf(" %d", &(cl->age));
  printf("Enter contact number: ");
  scanf(" %[^\n]s", cl->contact_num);
  int tempValCount = 1;
  for (int i = 0; i < 5; i++) {
    printf("Enter chapter-%d quiz: ", tempValCount);
    scanf(" %d", &(cl->task.quizzes[i]));
    tempValCount++;
  }
  printf("Enter prelim score: ");
  scanf(" %d", &(cl->task.prelim));
  printf("Enter midterm score: ");
  scanf(" %d", &(cl->task.midterm));
  printf("Enter final score: ");
  scanf(" %d", &(cl->task.final));
  system("clear");
}

void display_data(Classroom *cl) {
  printf("-- DISPLAY DATA --\n\n");
  printf("Name: %s %s %s\n", cl->first_name, cl->middle_name, cl->last_name);
  printf("Age: %d\n", cl->age);
  printf("Contact Number: %s\n", cl->contact_num);
  printf("- Scores Acquired -\n");
  int tempValCount = 1;
  for (int i = 0; i < 5; i++) {
    printf("Chapter-%d quiz: %d\n", tempValCount, cl->task.quizzes[i]);
    tempValCount++;
  }
  printf("Prelim Score: %d\n", cl->task.prelim);
  printf("Midterm Score: %d\n", cl->task.midterm);
  printf("Final Score: %d\n", cl->task.final);
  printf("\n");
}

void search_lastName(Classroom *cl, int maxStud) {
  char searchInp[MAX_LEN];
  printf("Search last name: ");
  scanf(" %[^\n]s", searchInp);

  int found = 0;
  for (int i = 0; i < maxStud; i++) {
    if (strcmp(cl[i].last_name, searchInp) == 0) {
      display_data(&cl[i]);
      found = 1;
    }
  }

  if (!found) {
    printf("No student found with the last name '%s'.\n", searchInp);
  }
}

void saveFile(Classroom *cl, int maxStud) {
  const char* filename = "Classroom Data.txt";

  // Check if the file exists
  if (access(filename, F_OK) == -1) {
    // File doesn't exist, create a new file and write the first line
    FILE *fpSave = fopen(filename, "w");
    if (fpSave == NULL) {
      printf("Failed to create the file.\n");
      return;
    }

    fprintf(fpSave, "-- CLASSROOM DATA --\n\n");
    fclose(fpSave);
  }

  // Open the file in append mode
  FILE *fpSave = fopen(filename, "a");
  if (fpSave == NULL) {
    printf("Failed to open the file for writing.\n");
    return;
  }

  // Append the data
  for (int i = 0; i < maxStud; i++) {
    fprintf(fpSave, "Name: %s %s %s\n", cl[i].first_name, cl[i].middle_name, cl[i].last_name);
    fprintf(fpSave, "Age: %d\n", cl[i].age);
    fprintf(fpSave, "Contact Number: %s\n", cl[i].contact_num);
    fprintf(fpSave, "- Scores Acquired -\n");
    int tempValCount = 1;
    for (int j = 0; j < 5; j++) {
      fprintf(fpSave, "Chapter-%d quiz: %d\n", tempValCount, cl[i].task.quizzes[j]);
      tempValCount++;
    }
    fprintf(fpSave, "Prelim Score: %d\n", cl[i].task.prelim);
    fprintf(fpSave, "Midterm Score: %d\n", cl[i].task.midterm);
    fprintf(fpSave, "Final Score: %d\n\n", cl[i].task.final);
  }

  fclose(fpSave);
  printf("Data saved successfully to 'Classroom Data.txt'.\n");
}

void showRank(Classroom *cl, int maxStud) {
  int students[maxStud];

  for (int i = 0; i < maxStud; i++) {
    int finalGrade = 0;
    int avgQuiz = 0;
    for (int j = 0; j < 5; j++) {
      avgQuiz += (cl + i)->task.quizzes[j];
    }

    int avgMajorExam = ((cl + i)->task.prelim + (cl + i)->task.midterm +
                        (cl + i)->task.final) /
                       3;

    finalGrade = (avgQuiz / 50) * 30 + (avgMajorExam / 60) * 70;

    students[i] = finalGrade;
  }

  for (int i = 0; i < maxStud; i++) {
    for (int j = i + 1; j < maxStud; j++) {
      if (students[j] > students[i]) {
        int temp = students[i];
        students[i] = students[j];
        students[j] = temp;
      }
    }
  }
  printf("-- RANKING --\n");
  for (int i = 0; i < maxStud; i++) {
    printf("Rank %d: %d\n", i + 1, students[i]);
  }
  printf("\n");
  menu(cl, maxStud);
}

void menu(Classroom *cl, int maxStud) {
  int choice;
  do {
    printf("-- MENU --\n");
    printf("1. Input Data\n");
    printf("2. Display Data\n");
    printf("3. Search by Last Name\n");
    printf("4. Save Data\n");
    printf("5. Show Ranking\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        system("clear");
        input_data(cl, maxStud);
        break;
      case 2:
        system("clear");
        display_data(cl);
        break;
      case 3:
        system("clear");
        search_lastName(cl, maxStud);
        break;
      case 4:
        system("clear");
        saveFile(cl, maxStud);
        break;
      case 5:
        system("clear");
        showRank(cl, maxStud);
        break;
      case 6:
        system("clear");
        printf("Exiting the program.\n");
        break;
      default:
        system("clear");
        printf("Invalid choice. Please try again.\n");
        break;
    }

    printf("\n");
  } while (choice != 6);
}

int main() {
  int max_stud = 1;
  Classroom cl[max_stud];
  Classroom *cl_ptr = cl;
  menu(cl_ptr, max_stud);
  return 0;
}
