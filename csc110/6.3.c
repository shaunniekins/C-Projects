#include <stdio.h>

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int remaining_time;
} Process;

void sort_processes(Process processes[], int num_process) {
    for (int i = 0; i < num_process - 1; i++) {
        for (int j = 0; j < num_process - i - 1; j++) {
            if (processes[j].arrival_time > processes[j + 1].arrival_time) {
                Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_process;

    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    printf("\n");

    Process processes[num_process];

    for (int i = 0; i < num_process; i++) {
        printf("Enter the burst time & arrival time of process %d: ", i + 1);
        scanf("%d %d", &processes[i].burst_time, &processes[i].arrival_time);
        processes[i].process_id = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
    }

    sort_processes(processes, num_process);

    int current_time = 0;
    int completed = 0;
    int waiting_times[num_process];
    int turnaround_times[num_process];

    for (int i = 0; i < num_process; i++) {
        waiting_times[i] = 0;
        turnaround_times[i] = 0;
    }

    while (completed != num_process) {
        int shortest_remaining = 9999, shortest_index = -1;

        for (int i = 0; i < num_process; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_remaining && processes[i].remaining_time > 0) {
                shortest_remaining = processes[i].remaining_time;
                shortest_index = i;
            }
        }

        if (shortest_index != -1) {
            processes[shortest_index].remaining_time--;
            current_time++;

            for (int i = 0; i < num_process; i++) {
                if (processes[i].arrival_time <= current_time && processes[i].remaining_time > 0 && i != shortest_index) {
                    waiting_times[i]++;
                }
            }

            if (processes[shortest_index].remaining_time == 0) {
                completed++;
                turnaround_times[shortest_index] = current_time - processes[shortest_index].arrival_time;
                waiting_times[shortest_index] = turnaround_times[shortest_index] - processes[shortest_index].burst_time;
            }
        } else {
            current_time++;
        }
    }

    printf("\nProcess | Burst Time | Waiting Time | Turnaround Time\n");
    for (int i = 0; i < num_process; i++) {
        printf("P%d\t|\t%d\t|\t%d\t|\t%d\n", processes[i].process_id, processes[i].burst_time, waiting_times[i], turnaround_times[i]);
    }

    return 0;
}