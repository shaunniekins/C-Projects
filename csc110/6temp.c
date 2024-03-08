#include <limits.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int waiting_time;
    int turnaround_time;
} Process;

int find_shortest_remaining_time(Process processes[], int num_process, bool arrived[]) {
    int min = INT_MAX, shortest = -1;
    for (int i = 0; i < num_process; i++) {
        if (arrived[i] && processes[i].burst_time < min) {
            min = processes[i].burst_time;
            shortest = i;
        }
    }
    return shortest;
}

void calculate_times(Process processes[], int num_process) {
    int remaining_burst_time[num_process];
    bool arrived[num_process];
    int time = 0;

    for (int i = 0; i < num_process; i++) {
        remaining_burst_time[i] = processes[i].burst_time;
        arrived[i] = false;
    }

    while (true) {
        bool done = true;
        for (int i = 0; i < num_process; i++) {
            if (time >= processes[i].arrival_time) {
                arrived[i] = true;
            }
            if (remaining_burst_time[i] > 0) {
                done = false;
            }
        }
        if (done) break;

        int shortest = find_shortest_remaining_time(processes, num_process, arrived);
        remaining_burst_time[shortest]--;
        time++;

        if (remaining_burst_time[shortest] == 0) {
            processes[shortest].turnaround_time = time - processes[shortest].arrival_time;
            processes[shortest].waiting_time = processes[shortest].turnaround_time - processes[shortest].burst_time;
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

    // calculate_times(processes, num_process);

    for (int i = 0; i < num_process; i++) {
        printf("Process %d: Waiting time = %d, Turnaround time = %d\n", i, processes[i].waiting_time, processes[i].turnaround_time);
    }

    //  for (int i = 0; i < num_process; i++) {
    //     printf("P%d\t\t", processes[i].process_id);
    //     printf("%d\t\t", processes[i].arrival_time);
    //     printf("%d\n", processes[i].burst_time);
    // }

    return 0;
}