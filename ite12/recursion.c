#include <stdio.h>

int factorial(int);

int main() {
    int inputtedNum;

    printf("Enter a number: ");
    scanf("%d", &inputtedNum);

    int factor = factorial(inputtedNum);
    printf("\n%d", factor);

    return 0;
}

int factorial(int n) {

    if (n==0) {
       return 1;
    }
    else {
        return n * factorial(n - 1);
    }
    
}