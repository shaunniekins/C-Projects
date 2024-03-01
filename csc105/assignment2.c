#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_REGISTER_VALUE 32

void conversion(int decimalNumber) {
    printf("You have entered register number %d with machine code equivalent of ", decimalNumber);
    
    for (int i = 4; i >= 0; i--) {
        printf("%d", (decimalNumber >> i) & 1);
    }
    
    printf(", a five-bit representation.\n");
}

int main() {
    int value;

    // Input value
    printf("Enter value: ");
    scanf("r%d", &value);

    // Check if the value is within the allowed total number of registers
    if (value < 0 || value > MAX_REGISTER_VALUE) {
        printf("Inputted register number exceeds the allowed value (0-%d).", MAX_REGISTER_VALUE);
    } else {
        conversion(value);
    }

    return 0;
}