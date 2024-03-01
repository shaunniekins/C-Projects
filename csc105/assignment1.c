#include <stdio.h>

// Function to print digits in big-endian order
void printBig(int num) {
    while (num > 0) {
        int digit = num % 10;
        printf("%d | ", digit);
        num /= 10;
    }
    printf("\n");
}

// Function to print digits in little-endian order
void printLittle(int num) {
    int digits[10];
    int count = 0;

    while (num > 0) {
        int digit = num % 10;
        digits[count] = digit;
        count++;
        num /= 10;
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d | ", digits[i]);
    }
    printf("\n");
}

int main() {
    int number;
    printf("Enter any numeric value: ");
    scanf("%d", &number);

    printf("Big Endian:\n");
    printBig(number);

    printf("Little Endian:\n");
    printLittle(number);

    return 0;
}
