#include <stdio.h>

int avg();
void remarks(int);
void isFail();


int failedCourseCounter = 0;
int numberOfCourses = 15;
void main(){
    int ave = avg();
    printf("Average Grade: %d\n", ave);
    remarks(ave);
    isFail();
}
int avg(){
    int i;
    int grade;
    int sum = 0;
    int average = 0;

    for(i = 0; i < numberOfCourses; i++){
        printf("Input grade:");
        scanf("%d", &grade);

        if(grade < 80) {
            failedCourseCounter++;
        }

        sum += grade;
    }
    average = sum / numberOfCourses;

    return (average);
}

void remarks(ave){
    if (ave > 95){
        printf("Outstanding");
    } else if (ave > 90 && ave < 95) {
        printf("Very Good Student");
    } else if (ave > 85 && ave < 90) {
        printf("Good Student");
    } else if (ave > 80 && ave < 85) {
        printf("Fair");
    } else if (ave < 80) {
        printf("Failed");
    }
}

void isFail(){
    if(failedCourseCounter > 5) {
        printf("\nAdvised to Shift\n");
    } else if(failedCourseCounter > 4 && failedCourseCounter <=5){
        printf("\nAdvised to Rest for 1 Sem");
    } else if(failedCourseCounter > 3 && failedCourseCounter <= 4){
        printf("\nAdvised to Take Counsel");
    }
}