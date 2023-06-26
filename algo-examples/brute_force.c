#include <stdio.h>

int brute_force_search(int arr[], int size, int key) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1; // not found
}

int main() {
    int arr[] = {4, 2, 1, 6, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 5;
    int index = brute_force_search(arr, size, key);
    if (index == -1) {
        printf("%d not found in array\n", key);
    } else {
        printf("%d found at index %d\n", key, index);
    }
    return 0;
}
