#include <stdio.h>

void sort(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                arr[i] = 0;
            }
        }
    }

}

int main() {
    int arr1[5] = {5, 4, 10, 4, 2};
    int arr2[4] = {11, 5, 2, 1};

    sort(arr1, 5);
    sort(arr2, 4);

    for (int i = 0; i < 5; i++) {
        printf("%d ", arr1[i] * arr2[i]);
    }

    return 0;
}