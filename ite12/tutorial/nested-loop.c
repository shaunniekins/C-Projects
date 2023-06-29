#include <stdio.h>

int main() {
    
    // i = 1;
    // j = 1;
    for(int i = 1; i <= 10; i++) { 
        //outer loop = row
        for (int j = 1; j <= 5; j++) {
            //inner loop = column
            printf("%4d", j);
        }
        printf("\n");
    }
}