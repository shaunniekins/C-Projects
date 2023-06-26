/**
A code that demonstrates the usage of a 2D array and its corresponding pointer array. It prompts the user to input numbers for each element of the 2D array, stores the values in the array, and assigns the respective addresses of each element to the pointer array. It then displays the values, addresses, and indices of the elements using the `show` function.
**/

#include <stdio.h>
#define ROW 2
#define COL 2

void inputReceiver(int arr[][COL], int * arrP[][COL])
{
  int i, j;
  for(i = 0; i < ROW; i++){
    for(j = 0; j < COL; j++) {
      printf("Input a number: ");
      scanf("%d", &arr[i][j]);
      arrP[i][j] = &arr[i][j];
    }
  }
}

void show(int arr[][COL], int * arrP[][COL])
{
  int i, j;
  for(i = 0; i < ROW; i++){
    for(j = 0; j < COL; j++) {
      printf("arr[%d][%d]: %d (Address: %u)", i, j, *(*(arr + i)  + j), arrP[i][j]);
      printf("\n");
    }
    printf("\n");
  }
}

int main()
{
  int arr[ROW][COL];
  int *arrPointer[ROW][COL];

  inputReceiver(arr, *arrPointer);
  show(arr, *arrPointer);

  return 0;
}