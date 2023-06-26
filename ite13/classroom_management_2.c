#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100

typedef struct Classroom {
  char student_id[SIZE];
  char first_name[SIZE];
  char middle_name[SIZE];
  char last_name[SIZE];
  int age;
  char contact_number[SIZE];
  int quizzes;
  int prelim;
  int midterm;
  int final_exam;
  float average_major;
  float average_quizzes;
  float average_over;
} Classroom;

int add(Classroom *classs, int counter) {
  int over_all = 0;
  fflush(stdin);
  printf("Add student's data:\n");
  getchar();
  printf("Student id: ");
  fgets(classs[counter].student_id, SIZE, stdin);
  printf("First name: ");
  fgets(classs[counter].first_name, SIZE, stdin);
  classs[counter].first_name[strcspn(classs[counter].first_name, "\n")] = '\0'; // Remove newline character
  printf("Middle name: ");
  fgets(classs[counter].middle_name, SIZE, stdin);
  classs[counter].middle_name[strcspn(classs[counter].middle_name, "\n")] = '\0'; // Remove newline character
  printf("Last name: ");
  fgets(classs[counter].last_name, SIZE, stdin);
  classs[counter].last_name[strcspn(classs[counter].last_name, "\n")] = '\0'; // Remove newline character
  printf("Age: ");
  scanf("%d", &classs[counter].age);
  getchar(); // Consume the newline character
  // fflush(stdin);
  printf("Contact number: ");
  fgets(classs[counter].contact_number, SIZE, stdin);
  printf("Quizzes #1 score / 50: ");
  scanf("%d", &over_all);
  classs[counter].quizzes = over_all;
  printf("Quizzes #2 score / 50: ");
  scanf("%d", &over_all);
  classs[counter].quizzes += over_all;
  printf("Quizzes #3 score / 50: ");
  scanf("%d", &over_all);
  classs[counter].quizzes += over_all;
  printf("Quizzes #4 score / 50: ");
  scanf("%d", &over_all);
  classs[counter].quizzes += over_all;
  printf("Quizzes #5 score / 50: ");
  scanf("%d", &over_all);
  classs[counter].quizzes += over_all;
  printf("Prelim Score / 60: ");
  scanf("%d", &classs[counter].prelim);
  if (classs[counter].prelim > 60) {
    printf("Score out of bounds");
    exit(0);
  }
  fflush(stdin);
  printf("Midterms / 60: ");
  scanf("%d", &classs[counter].midterm);
  if (classs[counter].midterm > 60) {
    printf("Score out of bounds");
    exit(0);
  }
  fflush(stdin);
  printf("Finals / 60: ");
  scanf("%d", &classs[counter].final_exam);
  if (classs[counter].final_exam > 60) {
    printf("Score out of bounds");
    exit(0);
  }
  classs[counter].average_major =
      (classs[counter].prelim + classs[counter].midterm +
       classs[counter].final_exam) /
      3.0;
  counter++;
  return counter;
}

void display(Classroom *classs, int counter) {
  int i;
  if (counter == 0) {
    printf("No data inputted");
    return;
  }
  for (i = 0; i < counter; i++) {
    printf("Student #%d id number: %s", i + 1, classs[i].student_id);
    printf("Student #%d Full name: %s %s %s\n", i + 1, classs[i].first_name,
           classs[i].middle_name, classs[i].last_name);
    printf("Student #%d Age: %d\n", i + 1, classs[i].age);
    printf("Student #%d Contact Num: %s", i + 1, classs[i].contact_number);
    printf("Student #%d Score Quizzes: %d / 250\n", i + 1, classs[i].quizzes);
    printf("Student #%d Score Prelim: %d / 60\n", i + 1, classs[i].prelim);
    printf("Student #%d Score Midterms: %d / 60\n", i + 1, classs[i].midterm);
    printf("Student #%d Score Finals: %d / 60\n", i + 1,
           classs[i].final_exam);
  }
}

void search(Classroom *classs, int counter) {
  int i;
  if (counter == 0) {
    printf("No data");
    return;
  }
  char search_name[SIZE];
  fflush(stdin);
  printf("Enter the name you want to search: ");
  fgets(search_name, SIZE, stdin);
  fflush(stdin);
  for (i = 0; i < counter; i++) {
    if (strstr(classs[i].first_name, search_name) != NULL ||
        strstr(classs[i].middle_name, search_name) != NULL ||
        strstr(classs[i].last_name, search_name) != NULL) {
      printf("Student #%d id number: %s", i + 1, classs[i].student_id);
      printf("Student #%d Full name: %s %s %s\n", i + 1, classs[i].first_name,
             classs[i].middle_name, classs[i].last_name);
      printf("Student #%d Age: %d\n", i + 1, classs[i].age);
      printf("Student #%d Contact Num: %s\n", i + 1, classs[i].contact_number);
      printf("Student #%d Score Quizzes: %d percent\n", i + 1,
             (classs[i].quizzes / 5));
      printf("Student #%d Average Exam Scores: %d percent\n", i + 1,
             (classs[i].prelim + classs[i].midterm + classs[i].final_exam) / 3);
    }
  }
}

void ranking(Classroom *classs, int counter) {
  int i, j;
  int arr[counter];
  for (i = 0; i < counter; i++) {
    classs[i].average_over =
        ((classs[i].quizzes / 50) / 50.0) * 30 +
        (((classs[i].prelim + classs[i].midterm + classs[i].final_exam) / 60.0) *
         70);
  }
  for (i = 0; i < counter; i++) {
    arr[i] = i;
  }
  for (i = 0; i < counter; i++) {
    for (j = i + 1; j < counter; j++) {
      if (classs[arr[i]].average_over < classs[arr[j]].average_over) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }
    }
  }
  for (i = 0; i < counter; i++) {
    printf("Rank %d: %.1f %s %s %s\n", i + 1, classs[arr[i]].average_over,
           classs[arr[i]].first_name, classs[arr[i]].middle_name,
           classs[arr[i]].last_name);
  }
}

void print(Classroom *classs, int counter) {
  int i;
  FILE *file = fopen("Classroom.txt", "w");
  if (file == NULL) {
    printf("Failed to create file.\n");
    return;
  }
  for (i = 0; i < counter; i++) {
    fprintf(file, "Full name: %s %s %s\n", classs[i].first_name,
            classs[i].middle_name, classs[i].last_name);
    fprintf(file, "Age: %d years old\n", classs[i].age);
    fprintf(file, "Contact Number: %s\n", classs[i].contact_number);
    fprintf(file, "Quizzes: %d\n", classs[i].quizzes);
    fprintf(file, "Prelim: %d\n", classs[i].prelim);
    fprintf(file, "Midterms: %d\n", classs[i].midterm);
    fprintf(file, "Finals: %d\n", classs[i].final_exam);
  }
  fclose(file);
}

int main(void) {
  int counter = 0, choice;
  Classroom classs[SIZE];

  system("clear");
  while (1) {
    printf("\n\nEnter function you want to perform:\n");
    printf("1. Add student data\n");
    printf("2. Display list of students\n");
    printf("3. Search for a student\n");
    printf("4. Show rank\n");
    printf("5. Save info to text file\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        system("clear");
        counter = add(classs, counter);
        break;
      case 2:
        system("clear");
        display(classs, counter);
        break;
      case 3:
        system("clear");
        search(classs, counter);
        break;
      case 4:
        system("clear");
        ranking(classs, counter);
        break;
      case 5:
        system("clear");
        print(classs, counter);
        break;
      case 6:
        system("clear");
        exit(0);
    }
  }

  return 0;
}
