#include <stdio.h>

int main() {
    
    // What is printed as the result of the following code?
    int a[] = {1, 4, 2, 3, 5};
    int b[] = {2, 1, 4, 5, 3};
    printf("%d", a[b[a[3]]]);

    return 0;
}

// //correct code
// #include <stdio.h>

// int main() {
    
//     printf("W");
//     int a[] = {1, 4, 2, 3, 5};
//     int b[] = {2, 1, 4, 5, 3};
//     printf("%d", a[b[3]]);

//     return 0;
// }