#include <stdio.h>

int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n-1) + fib(n-2);
}

int main() {
    int input;

    printf("Enter number: ");
    scanf("%d", &input);

    int recur = fib(input);
    printf("Fibonnaci: %d\n", recur);

    return 0;
}