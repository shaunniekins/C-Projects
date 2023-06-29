#include<stdio.h>

int averageNum();
int averageInterpretation(int);
void isFail();

int grade[15];
int main(){
    averageNum();

    return 0;
}

int averageNum(){

    int i = 0;
    int courses = 15;
    int total = 0;
    for (;i < courses; i++){
        printf("\nEnter your grades: ");
        scanf("%d", &grade[i]);
        total += grade[i];
    }
    total = total/courses;

    printf("Average grade is %d\n",  total);
    averageInterpretation(total);

    return 0;
}
int averageInterpretation(avg){
    if(avg > 95){
        printf("Outstanding student");
    } else if(avg > 90 && avg <= 95){
        printf("Very good student");
    } else if(avg > 85 && avg <= 90){
        printf("Good student");
    } else if(avg > 80 && avg <= 85){
        printf("Fair student");
    } else {
        printf("Failed");
    }

    isFail();
    return 0;
}

void isFail() {
    int failedSub;
    int i=15;
    for(;i>0;i--){
        if(grade[i] < 80){
            failedSub += grade[i];
        }
        int fail=grade[i];
    }
    if (failedSub > 5){
        printf("\nAdvised to shift");
    } else if(failedSub > 4 && failedSub <=5 ){
        printf("\nAdvised to rest for 1 sem");
    } else {
        printf("\nAdvised to take counsel");
    }
}