#include <stdio.h>

int main() {

  int gradeFirst, gradeSecond, gradeThird;

  // Input three grades from the user
  printf("Enter your first grade: ");
  scanf("%d", &gradeFirst);

  printf("Enter your second grade: ");
  scanf("%d", &gradeSecond);

  printf("Enter your third grade: ");
  scanf("%d", &gradeThird);

  // Print the three grades
  printf("Your grades: %d, %d, %d", gradeFirst, gradeSecond, gradeThird);

  return 0;
}