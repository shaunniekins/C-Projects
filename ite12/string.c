#include <stdio.h>

int main() {

    char name[] = "hey";
    char lastName[50];

    printf("%s", name);

    printf("Enter last name: ");
    gets(lastName);

    printf("%s", lastName);

    return 0;
}