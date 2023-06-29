#include <stdio.h>


int main() {

  float a, d, e, y;

  printf("Enter a-value: ");
  scanf("%f", &a);
  printf("Enter d-value: ");
  scanf("%f", &d);
  printf("Enter e-value: ");
  scanf("%f", &e);

  y = a+((d/e)*(a*a*a));

  printf("Answer: %.3f", y);


  return 0;
}
