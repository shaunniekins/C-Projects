/**
A code that allows the user to input values for a 3x3 array and then prints the array in a formatted manner. The `printArray` function takes a 2D array as a parameter and iterates over each element, printing it with a width of 20 characters. The `main` function declares a 3x3 array and prompts the user to input values for each element. Afterward, it calls the `printArray` function to display the array.
**/

#include <stdio.h>
#define ROW 3
#define COL 3

void printArray(int arr[][COL]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%20d  ", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[ROW][COL];

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("Input a value: ");
            scanf("%d", &arr[i][j]);
        }
        printf("\n\n");
    }

    printArray(arr);

    return 0;
}
