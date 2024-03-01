#include <stdio.h>

int binary_search(int arr[], int low, int high, int target)
{
    if (low > high) {
        return -1;  // target not found
    }

    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;  // target found at middle index
    } else if (arr[mid] > target) {
        // search left half of array
        return binary_search(arr, low, mid - 1, target);
    } else {
        // search right half of array
        return binary_search(arr, mid + 1, high, target);
    }
}

int main()
{
    int arr[] = {2, 5, 7, 11, 14, 16, 18};
    int n = sizeof(arr) / sizeof(int);
    int target = 14;

    int index = binary_search(arr, 0, n - 1, target);

    if (index == -1) {
        printf("Target not found\n");
    } else {
        printf("Target found at index %d\n", index);
    }

    return 0;
}
