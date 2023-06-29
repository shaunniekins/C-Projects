#include<stdio.h>


int main(){

    int num=20;
    int p1, p2,i, j, gcd;
    int start=2;
    for(i=num; i<=num+10; i++ ){
        gcd=1;
        if(i%2==0){
            p1 = i;
            p2 = i +30;

            for(j=1; j < p2; j++){
                if((p1%j==0) && (p2%j==0) )
                    gcd = j;
            }
            printf("the gcd of %d and %d is %d\n\n", p1, p2, gcd);
        }
    }
    return 0;
}
