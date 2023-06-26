#include <stdio.h>
#include <stdlib.h>

#define MAX_HEAP_SIZE 100

struct heap {
    int *data;
    int size;
    int capacity;
};

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

struct heap *create_heap(int capacity) {
    struct heap *h = (struct heap *)malloc(sizeof(struct heap));
    h->capacity = capacity;
    h->size = 0;
    h->data = (int *)malloc(capacity * sizeof(int));
    return h;
}

void insert(struct heap *h, int value) {
    if (h->size == h->capacity) {
        printf("Heap is full, cannot insert any more elements\n");
        return;
    }
    h->data[h->size++] = value;
    int i = h->size - 1;
    while (i > 0 && h->data[i] > h->data[(i - 1) / 2]) {
        swap(&h->data[i], &h->data[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extract_max(struct heap *h) {
    if (h->size == 0) {
        printf("Heap is empty, cannot extract any element\n");
        return -1;
    }
    int max_value = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (2 * i + 1 < h->size) {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int max_child = left_child;
        if (right_child < h->size && h->data[right_child] > h->data[left_child]) {
            max_child = right_child;
        }
        if (h->data[i] < h->data[max_child]) {
            swap(&h->data[i], &h->data[max_child]);
            i = max_child;
        } else {
            break;
        }
    }
    return max_value;
}

void print_heap(struct heap *h) {
    printf("Heap:\n");
    for (int i = 0; i < h->size; i++) {
        printf("%d ", h->data[i]);
    }
    printf("\n");
}

int main() {
    struct heap *h = create_heap(MAX_HEAP_SIZE);
    insert(h, 10);
    insert(h, 20);
    insert(h, 30);
    insert(h, 5);
    insert(h, 15);
    print_heap(h);
    int max_value = extract_max(h);
    printf("Extracted max value: %d\n", max_value);
    print_heap(h);
    return 0;
}
