#include <stdio.h>

int main() {
    int num = 10;

    for(int i = 1; i <= num; i++) {
        for(int j = 1; j <= num; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
}