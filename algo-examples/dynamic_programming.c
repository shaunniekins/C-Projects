#include <stdio.h>

int memo[100] = {0}; // array to store previously computed Fibonacci numbers

int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    if(memo[n] != 0)
    {
        return memo[n]; // return the previously computed Fibonacci number
    }
    memo[n] = fib(n-1) + fib(n-2); // compute the Fibonacci number and store it in the memo array
    return memo[n];
}

int main()
{
    int n = 10; // compute the 10th Fibonacci number
    int result = fib(n);
    printf("The %dth Fibonacci number is %d\n", n, result);
    return 0;
}
