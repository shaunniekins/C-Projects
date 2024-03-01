#include <stdio.h>
int main()
{
    int arr[] = {-2,1,-3,4,-1,2,1,-5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    int temp[9];
    int index[2];
    int i, j;
    int highest = 0, sum, tempsum;
    sum = 0;
    for(i=0; i<size; i++){
        sum += arr[i];
        if(sum < arr[i])
        {
            sum = arr[i];
        }
        temp[i] = sum;        
    }
    for (i=0; i<size; i++){
        if(highest < temp[i])
        {
            highest = temp[i];
            index[1] = i;
        }
    }
    for (i = 0; i < index[1]; i++)
    {
        if (temp[i] == arr[i])
        {
            index[0] = i;
        }
    }
    printf("%d to %d\n", index[0], index[1]);
    printf("%d\n", highest);
    return 0;
}