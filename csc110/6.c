// shortest remaining time first scheduling (pre-emptive version of SJF)

#include <stdio.h>
#define MAX_PROCESS_TIME 95

typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int elapsed_time;
} Process;

int find_shortest_burst_process(Process processes[], int num_process, int current_time) {
    int short_burst_process_index = -1;
    for(int i = 0; i < num_process; i++) {
        if(processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
            if(short_burst_process_index == -1 || processes[i].burst_time < processes[short_burst_process_index].burst_time)
                short_burst_process_index = i;
        }
    }
    return short_burst_process_index;
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

        while(remaining_processes != 0 && current_time < MAX_PROCESS_TIME) {
            while((current_process_index != -1 && current_time < MAX_PROCESS_TIME) || (remaining_processes == 1 && current_process_index == -1)) {
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

            while(current_process_index == -1 && current_time < MAX_PROCESS_TIME) {
                current_time++;
                current_process_index = find_shortest_burst_process(processes, num_process, current_time);
            }
        }

        printf("\n\nAvg waiting time: %f", (total_wait_time / processed_count));
        printf("\nAvg turnaround time: %f\n\n", (total_turn_around_time / processed_count));
    }
}

int main() {
    int num_process;
    int current_time = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    printf("\n");

    Process processes[num_process];

    for(int i = 0; i < num_process; i++){
        processes[i].process_id = i;
        processes[i].elapsed_time = 0;

        printf("Enter the burst time & arrival time of process %d: ", i + 1);
        scanf("%d %d",&processes[i].burst_time, &processes[i].arrival_time);
    }

    execute_processes(processes, num_process, current_time);

    return 0;
}