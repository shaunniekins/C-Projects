/**
A program that allows the user to enter a paragraph and converts all alphabetic characters in the paragraph to lowercase. It then prints the modified paragraph, with each word or character on a new line. The `convertToLowercase` function iterates over the characters in the paragraph, converts each character to lowercase using the `tolower` function from the `ctype.h` library, and prints the modified paragraph accordingly. The `main` function prompts the user to input the paragraph, reads it using `scanf`, and calls the `convertToLowercase` function to perform the lowercase conversion and formatting.
**/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convertToLowercase(char *txt, int txtLen) {
    for (int i = 0; i < txtLen; i++) {
        txt[i] = tolower(txt[i]);
        if (txt[i] == ' ') {
            printf("\n");
        } else {
            printf("%c", txt[i]);
        }
    }
}

int main() {
    int limNum = 50;
    char txt[limNum];

    printf("Enter a paragraph: ");
    scanf(" %[^\n]s", txt);

    convertToLowercase(txt, strlen(txt));

    return 0;
}
