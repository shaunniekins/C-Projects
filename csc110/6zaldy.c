//code1
// Include the standard input/output library
#include <stdio.h>

// Define a constant for the maximum time
#define MAX_TIME 200

// Declare global variables for the number of processList and the current time
int numProcesses = 0;
int currentTime = 0;

// Define a struct for the process
struct Process{
    int id, burstTime, arrivalTime, elapsedTime;
}processList[100]; // Declare an array of processList

// Function to get the number of processList from the user
void getNumProcesses(){
    // printf("Enter the no of processList - ");
    // scanf("%d",&numProcesses);
    numProcesses = 6;
}

// Function to get the burst time and arrival time for each process from the user
void getProcessDetails(){
    // for(int i=0; i<numProcesses ;i++){
    //     processList[i].id = i+1;
    //     processList[i].elapsedTime = 0;
    
    //     printf("Enter burst time for process %d - ",i+1);
    //     scanf("%d",&processList[i].burstTime);
    //     printf("Arrival time for process %d     - ",i+1);
    //     scanf("%d",&processList[i].arrivalTime);
    // }

    processList[0].id = 1;
    processList[0].arrivalTime = 0;
    processList[0].burstTime = 15;
    processList[0].elapsedTime = 0;

    processList[1].id = 2;
    processList[1].arrivalTime = 0;
    processList[1].burstTime = 20;
    processList[1].elapsedTime = 0;

    processList[2].id = 3;
    processList[2].arrivalTime = 20;
    processList[2].burstTime = 20;
    processList[2].elapsedTime = 0;

    processList[3].id = 4;
    processList[3].arrivalTime = 25;
    processList[3].burstTime = 20;
    processList[3].elapsedTime = 0;

    processList[4].id = 5;
    processList[4].arrivalTime = 45;
    processList[4].burstTime = 5;
    processList[4].elapsedTime = 0;

    processList[5].id = 6;
    processList[5].arrivalTime = 55;
    processList[5].burstTime = 15;
    processList[5].elapsedTime = 0;
}

// Function to find the process with the shortest remaining burst time that has arrived
int findShortestBurstProcess() {
    int shortestBurstProcessIndex = -1;
    for(int i = 0; i < numProcesses; i++) {
        if(processList[i].arrivalTime <= currentTime && processList[i].burstTime > 0) {
            if(shortestBurstProcessIndex == -1 || processList[i].burstTime < processList[shortestBurstProcessIndex].burstTime)
                shortestBurstProcessIndex = i;
        }
    }
    return shortestBurstProcessIndex;
}

// New function to handle the main program logic
void executeProcesses() {
    if(numProcesses <= 0) {
        printf("\nNO PROCESS INPUTED\n");
    } else {
        float waitTime = 0;
        float turnAroundTime = 0;
        float totalWaitTime = 0;
        float totalTurnAroundTime = 0;
        int processedCount = 0;
        int remainingProcesses = numProcesses;
        int currentProcessIndex = findShortestBurstProcess();
        int previousProcessIndex = currentProcessIndex;

        printf("\n\nProcess\t\tBurst-time\tWaiting-time\tturnaround-time\n");

        while(remainingProcesses != 0 && currentTime < MAX_TIME) {
            while((currentProcessIndex != -1 && currentTime < MAX_TIME) || (remainingProcesses == 1 && currentProcessIndex == -1)) {
                if(processList[currentProcessIndex].burstTime > 0) {
                    processList[currentProcessIndex].burstTime--;
                    processList[currentProcessIndex].elapsedTime++;
                }

                if((currentProcessIndex != previousProcessIndex && previousProcessIndex != -1) || (remainingProcesses == 1 && currentProcessIndex == -1)) {
                    turnAroundTime += processList[previousProcessIndex].elapsedTime;
                    totalTurnAroundTime += turnAroundTime;
                    printf("P%d\t\t%d\t\t%.0f\t\t%.0f\n", processList[previousProcessIndex].id, processList[previousProcessIndex].elapsedTime, waitTime, turnAroundTime);
                    totalWaitTime += waitTime;
                    waitTime += processList[previousProcessIndex].elapsedTime;
                    processedCount++;
                    if(processList[previousProcessIndex].burstTime <= 0) {
                        remainingProcesses--;
                    }
                    processList[previousProcessIndex].elapsedTime = 0;
                }

                previousProcessIndex = currentProcessIndex;
                currentTime++;
                currentProcessIndex = findShortestBurstProcess();
            }

            while(currentProcessIndex == -1 && currentTime < MAX_TIME) {
                currentTime++;
                currentProcessIndex = findShortestBurstProcess();
            }
        }

        printf("\n\nAvg waiting time: %f", (totalWaitTime / processedCount));
        printf("\nAvg turnaround time: %f\n\n", (totalTurnAroundTime / processedCount));
    }
}

int main() {
    getNumProcesses();
    getProcessDetails();
    executeProcesses();
    return 0;
}