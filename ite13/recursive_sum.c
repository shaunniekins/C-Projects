/**
A program that calculates the sum of numbers from 1 to a given input value using a recursive function. The `sumRecur` function takes an integer parameter `n` and recursively calculates the sum by adding `n` with the sum of numbers from 1 to `n-1`. The main function prompts the user to input a value, calls the `sumRecur` function with the input value, and then displays the calculated sum using a printf statement.
**/

#include <stdio.h>

int sumRecur(int n) {
  if (n == 0)
    return 0;
  else
    return n + sumRecur(n - 1);
}

int main() {
  int inputVal, totalSum;

  printf("Input value: ");
  scanf("%d", &inputVal);

  totalSum = sumRecur(inputVal);

  printf("The sum of numbers from 1 to %d is: %d\n", inputVal, totalSum);

  return 0;
}
