// shortest remaining time first scheduling (pre-emptive version of SJF) with static data

#include <stdio.h>
#define INT_MAX 95

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int elapsed_time;
} Process;

int find_shortest_burst_process(Process processes[], int num_process, int current_time) {
    int shortestBurstProcessIndex = -1;
    for(int i = 0; i < num_process; i++) {
        if(processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
            if(shortestBurstProcessIndex == -1 || processes[i].burst_time < processes[shortestBurstProcessIndex].burst_time)
                shortestBurstProcessIndex = i;
        }
    }
    return shortestBurstProcessIndex;
}

void execute_processes(Process processes[], int num_process, int current_time) {
    if(num_process <= 0) {
        printf("\nNO PROCESS INPUTED\n");
    } else {
        float wait_time = 0;
        float turn_around_time = 0;
        float total_wait_time = 0;
        float total_turn_around_time = 0;
        int processed_count = 0;
        int remaining_processes = num_process;
        int current_process_index = find_shortest_burst_process(processes, num_process, current_time);
        int previous_process_index = current_process_index;

        printf("\n\nProcess\t\tBurst-time\tWaiting-time\tturnaround-time\n");

        while(remaining_processes != 0 && current_time < INT_MAX) {
            while((current_process_index != -1 && current_time < INT_MAX) || (remaining_processes == 1 && current_process_index == -1)) {
                if(processes[current_process_index].burst_time > 0) {
                    processes[current_process_index].burst_time--;
                    processes[current_process_index].elapsed_time++;
                }

                if((current_process_index != previous_process_index && previous_process_index != -1) || (remaining_processes == 1 && current_process_index == -1)) {
                    turn_around_time += processes[previous_process_index].elapsed_time;
                    total_turn_around_time += turn_around_time;
                    printf("P%d\t\t%d\t\t%.0f\t\t%.0f\n", processes[previous_process_index].process_id + 1, processes[previous_process_index].elapsed_time, wait_time, turn_around_time);
                    total_wait_time += wait_time;
                    wait_time += processes[previous_process_index].elapsed_time;
                    processed_count++;
                    if(processes[previous_process_index].burst_time <= 0) {
                        remaining_processes--;
                    }
                    processes[previous_process_index].elapsed_time = 0;
                }

                previous_process_index = current_process_index;
                current_time++;
                current_process_index = find_shortest_burst_process(processes, num_process, current_time);
            }

            while(current_process_index == -1 && current_time < INT_MAX) {
                current_time++;
                current_process_index = find_shortest_burst_process(processes, num_process, current_time);
            }
        }

        printf("\n\nAvg waiting time: %f", (total_wait_time / processed_count));
        printf("\nAvg turnaround time: %f\n\n", (total_turn_around_time / processed_count));
    }
}

int main() {
    int num_process = 6;
    int current_time = 0;

    Process processes[num_process];

    // hardcoded data
    processes[0].process_id = 0;
    processes[0].arrival_time = 0;
    processes[0].burst_time = 15;
    processes[0].elapsed_time = 0;

    processes[1].process_id = 1;
    processes[1].arrival_time = 0;
    processes[1].burst_time = 20;
    processes[1].elapsed_time = 0;

    processes[2].process_id = 2;
    processes[2].arrival_time = 20;
    processes[2].burst_time = 20;
    processes[2].elapsed_time = 0;

    processes[3].process_id = 3;
    processes[3].arrival_time = 25;
    processes[3].burst_time = 20;
    processes[3].elapsed_time = 0;

    processes[4].process_id = 4;
    processes[4].arrival_time = 45;
    processes[4].burst_time = 5;
    processes[4].elapsed_time = 0;

    processes[5].process_id = 5;
    processes[5].arrival_time = 55;
    processes[5].burst_time = 15;
    processes[5].elapsed_time = 0;

    // sort_processes(processes, num_process);
    execute_processes(processes, num_process, current_time);

    return 0;
}