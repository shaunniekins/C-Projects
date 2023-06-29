#include <stdio.h>


int main() {

  float a, b, d, y;

  printf("Enter a-value: ");
  scanf("%f", &a);
  printf("Enter b-value: ");
  scanf("%f", &b);
  printf("Enter d-value: ");
  scanf("%f", &d);

  y = ((a*b)/((2*b)-a))*d;

  printf("Answer: %.3f", y);


  return 0;
}
