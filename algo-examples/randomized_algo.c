#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, num;
    srand(time(NULL)); // seed the random number generator with current time
    for(i = 0; i < 10; i++)
    {
        num = rand() % 100 + 1; // generate a random integer between 1 and 100
        printf("%d ", num); // print the generated integer
    }
    return 0;
}
