#include <stdio.h>
#define MAX 100

struct os{
    int id;
    int burst;
    int arr;
    int elapsed;
};


int sort(struct os p[], int size){
    int i, j;
    struct os temp;
    for(i=0; i<size; i++){
        for(j=0; j<size-1; j++){
            if(p[j].arr>p[j+1].arr){
                temp = p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
        }
    }
}

int shortestBurst(struct os p[], int size, int curTime){
    int index = -1;
    for(int i = 0; i < size; i++) {
        if(p[i].arr <= curTime && p[i].burst > 0) {
            if(index == -1 || p[i].burst < p[index].burst)
                index = i;
        }
    }
    return index;
}


void SRTFS(struct os p[], int size, int curTime) {
    if(size <= 0) {
        printf("\nNO PROCESS INPUTED\n");
    } else {
        float wait = 0, turn = 0, sumWait = 0, sumTurn = 0;
        int counter = 0, notProcessed = size;
        int index = shortestBurst(p, size, curTime);
        int prevIndex = index;

        printf("\n\nProcess\t\tBurst-time\tWaiting-time\tTurnaround-Time\n");

        while(notProcessed != 0 && curTime < MAX) {
            while((index != -1 && curTime < MAX) || (notProcessed == 1 && index == -1)) {
                if(p[index].burst > 0) {
                    p[index].burst--;
                    p[index].elapsed++;
                }

                if((index != prevIndex && prevIndex != -1) || (notProcessed == 1 && index == -1)) {
                    turn += p[prevIndex].elapsed;
                    sumTurn += turn;
                    printf("P%d\t\t%d\t\t%.0f\t\t%.0f\n", p[prevIndex].id + 1, p[prevIndex].elapsed, wait, turn);
                    sumWait += wait;
                    wait += p[prevIndex].elapsed;
                    counter++;
                    if(p[prevIndex].burst <= 0) {
                        notProcessed--;
                    }
                    p[prevIndex].elapsed = 0;
                }

                prevIndex = index;
                curTime++;
                index = shortestBurst(p, size, curTime);
            }

            while(index == -1 && curTime < MAX) {
                curTime++;
                index = shortestBurst(p, size, curTime);
            }
        }

        printf("\n\nAvg waiting time: %f", (sumWait / counter));
        printf("\nAvg turnaround time: %f\n\n", (sumTurn / counter));
    }
}

int main(){

    int size, current=0, i;


    printf("Enter number of proccesses:\t");
    scanf("%d",  &size);

    struct os p[size];

    for(i=0; i<size; i++){
        printf("\nEnter arrival time for Process %d:\t", i+1);
        scanf("%d", &p[i].arr);
        printf("\nEnter burst time:\t");
        scanf("%d", &p[i].burst);
        p[i].id=i;
        p[i].elapsed = 0;
    }

    sort(p, size);
    SRTFS(p, size, current);

    return 0;
}

