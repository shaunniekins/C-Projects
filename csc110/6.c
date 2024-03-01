// shortest remaining time first scheduling (preemptive version of SJF)

#include <stdio.h>

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
} Process;

// sorting for arrival time
void swap(Process *xp, Process *yp) {
    Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(Process processes[], int num_process) {
    int i, j;
    for (i = 0; i < num_process-1; i++) {
        for (j = 0; j < num_process-i-1; j++) {
            if (processes[j].arrival_time > processes[j+1].arrival_time)
                swap(&processes[j], &processes[j+1]);
        }
    }
}

// scheduling based on arrival time preemptive
void scheduler(Process processes[], int num_process) {
    int i, j;
    int currentTime = processes[0].arrival_time;
    int processId[num_process];
    int remainingTime[num_process];

    for (i = 0; i < num_process-1; i++) {
        if (currentTime == processes[i].arrival_time) {
            processId[i] = processes[i].process_id;
            remainingTime[i] = processes[i].burst_time;
        }
    }
}

int main() {
    // int num_process;
    int num_process = 6;

    // printf("Enter the number of processes: ");
    // scanf("%d", &num_process);
    // printf("\n");

    Process processes[num_process];


    // for (int i = 0; i < num_process; i++) {
    //     printf("Enter the burst time & arrival time of process %d: ", i);
    //     scanf("%d %d",&processes[i].arrival_time, &processes[i].burst_time);
    //     processes[i].process_id = i;
    // }

    // hardcoded data
    processes[0].process_id = 0;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 15;

    processes[1].process_id = 1;
    processes[1].arrival_time = 0;
    processes[1].burst_time = 20;

    processes[2].process_id = 2;
    processes[2].arrival_time = 20;
    processes[2].burst_time = 20;

    processes[3].process_id = 3;
    processes[3].arrival_time = 25;
    processes[3].burst_time = 20;

    processes[4].process_id = 4;
    processes[4].arrival_time = 45;
    processes[4].burst_time = 5;

    processes[5].process_id = 5;
    processes[5].arrival_time = 55;
    processes[5].burst_time = 15;

    // sort(processes, num_process);
    scheduler(processes, num_process);



    // for (int i = 0; i < num_process; i++) {
    //     printf("P%d\t\t", processes[i].process_id);
    //     printf("%d\t\t", processes[i].arrival_time);
    //     printf("%d\n", processes[i].burst_time);
    // }

    return 0;
}