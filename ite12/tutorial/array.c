#include <stdio.h>


/*
    Write a program in C to separate odd and even integers in separate arrays. Go to the editor
    Test Data :
    Input the number of elements to be stored in the array :5
    Input 5 elements in the array :
    element - 0 : 25
    element - 1 : 47
    element - 2 : 42
    element - 3 : 56
    element - 4 : 32
    Expected Output :
    The Even elements are :
    42 56 32
    The Odd elements are :
    25 47
*/

int main() {
    int elements[5] = {25, 47, 42, 56, 32};
    int even[5];
    int odd[5];
    int countEven = 0;
    int countOdd = 0;

    for(int i = 0; i < 5; i++) {
        if (elements[i] % 2 == 0) {
            even[i] = elements[i];
            countEven += 1;
        }
        else {
            odd[i] = elements[i];
            countOdd += 1;
        }
    }
    printf("The even elements are: ");
    for(int i = 0; i < countEven; i++) {
        printf("%d ", even[i]);
    }

    printf("\nThe odd elements are: ");
    for(int i = 0; i < countOdd; i++) {
        printf("%d ", odd[i]);
    }

    return 0 ;
}