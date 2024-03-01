#include <stdio.h>

void asc(int numbers[], int num) {
    int temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void desc(int numbers[], int num) {
    int temp;
    for (int i = 0; i < num - 1; i++) {
        for (int j = 0; j < num - i - 1; j++) {
            if (numbers[j] < numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num;
    
    printf("How many numbers: ");
    scanf("%d", &num);
    
    int numbers[num];
    
    for (int i = 0; i < num; i++) {
        printf("Enter num[%d]: ", i + 1);
        scanf("%d", &numbers[i]); 
    }
    
    printf("\n\nA. Ascending\nB. Descending\nC. Exit\n");
    char choice;
    printf("Choice: ");
    scanf(" %c", &choice);
    
    switch(choice) {
        case 'A':
        case 'a':
            asc(numbers, num);
            printf("Ascending order: ");
            break;
        case 'B':
        case 'b':
            desc(numbers, num);
            printf("Descending order: ");
            break;
        case 'C':
        case 'c':
            return 0;
        default:
            printf("Invalid choice.\n");
            return 1;
    }
    
    for (int i = 0; i < num; i++) {
        printf("%d ", numbers[i]);
    }
    
    return 0;
}
