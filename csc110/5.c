#include <stdio.h>
#define BUFFER_SIZE 10

void display(int buffer_arr[]) {
    printf("Buffer: ");
    for (int i = 0; i < BUFFER_SIZE; i++) {
        printf("%d ", buffer_arr[i]);
    }
    printf("\t");
}

int arranger(int buffer_arr[]) {
    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (buffer_arr[BUFFER_SIZE - 1] < 0) {
            buffer_arr[BUFFER_SIZE - 1] = 0;
        }
        
        if (buffer_arr[i] == 0) {
            buffer_arr[i] = buffer_arr[i + 1];
            buffer_arr[i + 1] = 0;
            buffer_arr[BUFFER_SIZE - 1] = 0;
        }
    }
}

int produce(int buffer_arr[]) {
    int item;

    printf("Enter the value: ");
    scanf("%d", &item);

    if (buffer_arr[BUFFER_SIZE - 1] != 0) {
        printf("-- Buffer is full --\n");
        return 0;
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (buffer_arr[i] == 0) {
            buffer_arr[i] = item;
            break;
        }
    }
    display(buffer_arr);
}

int consume(int buffer_arr[]) {
    int item;

    if (buffer_arr[0] == 0) {
        printf("-- Buffer is empty --\n");
        return 0;
    }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        if (buffer_arr[i] != 0) {
            item = buffer_arr[i];
            buffer_arr[i] = 0;
            break;
        }
    }

    printf("Consumed: %d\n", item);
    arranger(buffer_arr);
    display(buffer_arr);
}

void menu(int buffer_arr[], int choice) {

    printf("\n\n1. Produce\n");
    printf("2. Consume\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            produce(buffer_arr);
            menu(buffer_arr, choice);
            break;
        case 2:
            consume(buffer_arr);
            menu(buffer_arr, choice);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice\n");
            menu(buffer_arr, choice);
            break;
    }
}

int main() {
    int buffer_arr[BUFFER_SIZE];
    int choice;

    // for (int i = 0; i < BUFFER_SIZE; i++) {
    //    printf("%d ", buffer_arr[i]);
    // }

    for (int i = 0; i < BUFFER_SIZE; i++) {
        buffer_arr[i] = 0;
    }

    menu(buffer_arr, choice);

    return 0;
}