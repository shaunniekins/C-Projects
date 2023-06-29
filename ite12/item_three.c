#include <stdio.h>

int main() {

  int ageFirst, ageSecond, ageThird;

  // Input three age from the user
  printf("Enter first age: ");
  scanf("%d", &ageFirst);

  printf("Enter second age: ");
  scanf("%d", &ageSecond);

  printf("Enter third age: ");
  scanf("%d", &ageThird);

  // Print three inputted age
  printf("The three ages: %d, %d, %d", ageFirst, ageSecond, ageThird);

  return 0;
}