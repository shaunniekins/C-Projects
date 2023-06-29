#include <stdio.h>


int main() {

  float a, b, c, y;

  printf("Enter a-value: ");
  scanf("%f", &a);
  printf("Enter b-value: ");
  scanf("%f", &b);
  printf("Enter c-value: ");
  scanf("%f", &c);

  y = (a*b)+c;
  
  printf("Answer: %.3f", y);


  return 0;
}
