//memoization
#include <stdio.h>

int fib(int n, int memo[]) {
    if (memo[n] != -1) {
        return memo[n];
    }
    if (n <= 1) {
        memo[n] = n;
    } else {
        memo[n] = fib(n-1, memo) + fib(n-2, memo);
    }
    return memo[n];
}

int main() {
    int n;

    printf("Enter number: ");
    scanf("%d", &n);
    
    int memo[n+1];
    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }
    printf("%d", fib(n, memo));
    
    return 0;
}
