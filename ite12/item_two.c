#include <stdio.h>

int main() {

  char charOne, charTwo, charThree;

  // Input three characters from the user
  printf("Enter first character: ");
  scanf(" %c", &charOne);

  printf("Enter second character: ");
  scanf(" %c", &charTwo);

  printf("Enter third character: ");
  scanf(" %c", &charThree);

  // Print the three characters
  printf("The three characters: %c, %c, %c", charOne, charTwo, charThree);

  return 0;
}