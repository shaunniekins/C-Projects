#include<stdio.h>

int main(){

    char letter = 'a';
    int middle =11;
    int i=0,j=0, k=-1, l=-1;;
    for(j=0;j<11;j++){
        letter ='a';
        for(i=1;i<=21;i++){
            if(i<middle){
                if(i>=middle-k && j>1)
                    printf("   ");
                else
                    printf("%c  ", letter++);

            }
            if(i==middle){
                if(j>0)
                    printf("   ");
                else
                    printf("%c  ", letter);
                --letter;

            }
            if(i>middle){
                if(l!=0&& j>1){
                    printf("   ");
                    l--;
                }
                else
                    printf("%c  ", letter--);
            }
        }
        k++;
        l=k;
        printf("\n");
    }

    return 0;
}
