#include <stdio.h>

int main() {

    int arr1[5] = {2, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    int arr3[5];

    int i = 0;
    for(; i < 5; i++) {
        arr3[i] = arr1[i] + arr2[i]; 
        printf("arr3[%d]: %d\n", i, arr3[i]);
    }

    return 0;
}