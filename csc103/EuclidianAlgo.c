#include <stdio.h>

// recursion
//  int algo(int a, int b) {
//    if (b == 0) {
//      return a;
//    } else {
//      algo(b, a % b);
//    }
//  }

// iterative
int algo(int a, int b) {
  int temp;
  while (b != 0) {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int main() {
  int a, b, gcd;

  printf("Enter first value: ");
  scanf("%d", &a);
  printf("Enter second value: ");
  scanf("%d", &b);
  gcd = algo(a, b);

  printf("GCD is %d.", gcd);

  return 0;
}