//tabulation

#include <stdio.h>

int fib(int n) {
    int fib_nums[n+1];
    fib_nums[0] = 0;
    fib_nums[1] = 1;
    for (int i = 2; i <= n; i++) {
        fib_nums[i] = fib_nums[i-1] + fib_nums[i-2];
    }
    return fib_nums[n];
}

int main() {
     int input;

    printf("Enter number: ");
    scanf("%d", &input);

    printf("Fibonacci number at position %d is %d\n", input, fib(input));
    return 0;
}
