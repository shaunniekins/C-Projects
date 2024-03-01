#include <stdio.h>

#define MAX 100

int memo[MAX];

int canSum(int targetValue, int numbers[], int size) {
    if (targetValue == 0) {
        return 1;
    }
    if (targetValue < 0) {
        return 0;
    }
    if (memo[targetValue] != -1) {
        return memo[targetValue];
    }
    for (int i = 0; i < size; i++) {
        int remainder = targetValue - numbers[i];
        printf("%d = %d - %d\n", remainder, targetValue, numbers[i]);
        if (canSum(remainder, numbers, size) == 1) {
            memo[targetValue] = 1;
            return 1;
        }
    }
    memo[targetValue] = 0;
    return 0;
}

int main() {
    int targetValue, size, result;

    printf("Enter target sum: ");
    scanf("%d", &targetValue);

    printf("Enter size of array: ");
    scanf("%d", &size);

    int numbers[size];
    for (int i = 0; i < size; i++) {
        printf("Enter number[%d]: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i <= targetValue; i++) {
        memo[i] = -1;
    }

    result = canSum(targetValue, numbers, size);
    printf("Result: %d\n", result);

    return 0;
}