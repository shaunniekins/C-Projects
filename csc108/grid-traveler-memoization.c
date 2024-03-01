#include <stdio.h>

#define MAX_ROWS 100
#define MAX_COLS 100

int memo[MAX_ROWS][MAX_COLS];

int gridTraveler(int rows, int columns) {
    if (memo[rows][columns] != 0) {
        return memo[rows][columns];
    }
    if (rows == 1 && columns == 1) {
        return 1;
    }
    if (rows == 0 || columns == 0) {
        return 0;
    }
    int initialRows = rows;
    int initialCols = columns;
    int deductedRows = rows - 1;
    int deductedCols = columns - 1;
    printf("Whole: (%d, %d) , (%d, %d)\n", deductedRows, initialCols, initialRows, deductedCols);

    int result = gridTraveler(rows - 1, columns) + gridTraveler(rows, columns - 1);
    printf("result: %d\n",result);
    memo[rows][columns] = result;
    return result;
}

int main() {
    int rows, columns, result;

    printf("# of rows: ");
    scanf("%d", &rows);

    printf("# of columns: ");
    scanf("%d", &columns);

    result = gridTraveler(rows, columns);
    printf("Number of ways to travel the grid: %d\n", result);

    return 0;
}
