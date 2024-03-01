//selection sort algorithm

#include <stdio.h>

void selection_sort(int arr[], int n) {
    int count = 0; //to check how many loops happened

    for (int i = 0; i < n - 1; i++) {
        int min = i;

        for (int j = i + 1; j < n; j++) {
            count++;
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        if (min != i) {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("%d\n", count);
}

int main() {
    int arr[] = {1, 7, 6, 8, 12, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // printf("\nUnsorted: \t");
    // for (int i = 0; i < n; i++) {
    //     printf("%d ", arr[i]);
    // }

    selection_sort(arr, n);

    printf("\nSorted: \t");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
