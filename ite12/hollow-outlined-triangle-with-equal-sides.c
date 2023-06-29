#include<stdio.h>
#define bool int
#define true 1
#define false 0

bool inRange(int lowerLimit, int upperLimit, int no)
{
    return (lowerLimit < no && no < upperLimit);
}
int main(){
/*
OUTPUT MUST BE
     *
    * *
   *   *
  *     *
 * * * * *

*/
int i,j;
int middle = 5, num_to_print = 0, last_num=1;

for (i=1;i<=5;i++){
    for (j=1;j<=9;j++){
        if(i==5){
            if(j%2){
                printf("*");
            }
            else{
                 printf("   ");
            }
        }
        else if((inRange(middle, middle+num_to_print, j)==1)&&(i!=5)){
            printf("  ");
        }
        else if(j>=middle && j<=middle+num_to_print && i!=5){
            printf("* ");
        }
        else
            printf("  ");
    }
    middle--;
    num_to_print+=2;
    printf("\n");
}














return 0;
}
