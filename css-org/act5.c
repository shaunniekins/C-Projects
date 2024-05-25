#include <stdio.h>

int main() {
    int a = 5;

    if (a) a += 1;
    if (a != a) a -= a;
    else a = 0;

    printf("%i %s\n", a++, "+ 1");

    return 0;
}