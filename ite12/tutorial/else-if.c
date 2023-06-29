#include <stdio.h>

int main() {
    /*
    Percentage >= 90% : Grade A
    Percentage >= 80% : Grade B
    Percentage >= 70% : Grade C
    Percentage >= 60% : Grade D
    Percentage >= 40% : Grade E
    Percentage < 40% : Grade F
    */
   int percentage;

   printf("Enter your percentage: ");
   scanf("%d", &percentage);

   if (percentage >= 90) {
        printf("Grade A");
   } else if (percentage >= 80) {
        printf("Grade B");
   } else if (percentage >= 70) {
        printf("Grade C");
   } else if (percentage >= 60) {
        printf("Grade D");
   } else if (percentage >= 40) {
        printf("Grade E");
   } else {
        printf("Grade F");
   }

    return 0;
}