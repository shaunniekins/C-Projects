#include<stdio.h>


int main(){

    char letter = 'a';
    int i,j, k=0, l;

    for(i=0; i<5;i++){
        letter='a';
        k=i;
        l=i;
        for(j=0; j< 9;j++){
            if(k==0){
                if(j==(9-l)){
                    break;
                }else
                    printf("%c  ", letter++);

            }else{
                printf("   ");
                letter++;
                k--;
            }
        }
        printf("\n");

    }


    return 0;
}
