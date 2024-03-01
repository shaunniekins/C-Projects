#include <stdio.h>

void selection_sort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

int main() {
    int arr[] = { 64, 25, 12, 22, 11 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    printf("Array before sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selection_sort(arr, size);

    printf("Array after sorting:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
//selection sort
