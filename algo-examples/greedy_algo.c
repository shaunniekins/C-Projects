#include <stdio.h>

void make_change(int coins[], int num_coins, int value)
{
    int i, count;
    for (i = 0; i < num_coins; i++) {
        count = value / coins[i];
        if (count > 0) {
            printf("%d x %d cents\n", count, coins[i]);
            value -= count * coins[i];
        }
    }
}

int main()
{
    int coins[] = {25, 10, 5, 1};
    int num_coins = sizeof(coins) / sizeof(int);
    int value = 41;

    make_change(coins, num_coins, value);

    return 0;
}

//greedy algo