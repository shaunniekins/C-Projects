#include <stdio.h>

int Prime(int num) {
    if (num <= 1) {
        return 0; // 0 and 1 are not prime numbers
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0; // It's not a prime number
        }
    }
    return 1; // It's a prime number
}

int main() {
    int n;
    
    printf("Enter the value of n: ");
    scanf("%d", &n);
    
    printf("First %d prime numbers are:\n", n);
    
    int count = 0;
    int number = 2;
    
    while (count < n) {
        if (Prime(number)) {
            printf("%d ", number);
            count++;
        }
        number++;
    }
    
    printf("\n");
    
    return 0;
}
