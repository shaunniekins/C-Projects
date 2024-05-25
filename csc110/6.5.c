// shortest remaining time first scheduling (pre-emptive version of SJF)

#include <stdio.h>
#define INT_MAX 999

// Define a structure for the process
typedef struct Process {
    int process_id;
    int arrival_time;
    int burst_time;
    int elapsed_time;
} Process;

// Function to find the process with the shortest burst time that has already arrived
int find_shortest_burst_process(Process processes[], int num_process, int current_time) {
    int shortestBurstProcessIndex = -1;
    for(int i = 0; i < num_process; i++) {
        // Check if the process has arrived and still has some burst time left
        if(processes[i].arrival_time <= current_time && processes[i].burst_time > 0) {
            // If this is the first such process or if its burst time is less than the current shortest, update shortestBurstProcessIndex
            if(shortestBurstProcessIndex == -1 || processes[i].burst_time < processes[shortestBurstProcessIndex].burst_time)
                shortestBurstProcessIndex = i;
        }
    }
    return shortestBurstProcessIndex;
}

// Function to execute the processes using the SRTF scheduling algorithm
void execute_processes(Process processes[], int num_process, int current_time) {
    if(num_process <= 0) {
        printf("\nNO PROCESS INPUTED\n");
    } else {
        // Initialize variables to keep track of the total waiting time, total turnaround time, the number of processed processes, and the remaining processes
        float wait_time = 0;
        float turn_around_time = 0;
        float total_wait_time = 0;
        float total_turn_around_time = 0;
        int processed_count = 0;
        int remaining_processes = num_process;

        // Find the index of the process with the shortest burst time that has already arrived
        int current_process_index = find_shortest_burst_process(processes, num_process, current_time);
        int previous_process_index = current_process_index;

        printf("\n\nProcess\t\tBurst-time\tWaiting-time\tturnaround-time\n");

        // Loop until all processes have been processed or the current time has reached the maximum integer value
        while(remaining_processes != 0 && current_time < INT_MAX) {
            // Loop while the current process has burst time left or if it's the last remaining process
            while((current_process_index != -1 && current_time < INT_MAX) || (remaining_processes == 1 && current_process_index == -1)) {
                // Decrease the burst time of the current process by 1 and increase its elapsed time by 1 for each time unit
                if(processes[current_process_index].burst_time > 0) {
                    processes[current_process_index].burst_time--;
                    processes[current_process_index].elapsed_time++;
                }

                // If the current process changes or if it's the last remaining process, calculate the turnaround time for the previous process, update the total turnaround time and total waiting time, print the process details, and reset the elapsed time of the previous process
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

                // Update the current process index to the process with the shortest remaining burst time that has already arrived
                previous_process_index = current_process_index;
                current_time++;
                current_process_index = find_shortest_burst_process(processes, num_process, current_time);
            }

            // If no process with the shortest remaining burst time that has already arrived is found, increase the current time until a process arrives
            while(current_process_index == -1 && current_time < INT_MAX) {
                current_time++;
                current_process_index = find_shortest_burst_process(processes, num_process, current_time);
            }
        }

        // Calculate and print the average waiting time and average turnaround time
        printf("\n\nAvg waiting time: %f", (total_wait_time / processed_count));
        printf("\nAvg turnaround time: %f\n\n", (total_turn_around_time / processed_count));
    }
}

int main() {
    int num_process;
    int current_time = 0;

    // Ask the user for the number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    printf("\n");

    // Initialize the processes array
    Process processes[num_process];

    // Ask the user for the burst time and arrival time of each process
    for(int i = 0; i < num_process; i++){
        processes[i].process_id = i;
        processes[i].elapsed_time = 0;

        printf("Enter the burst time & arrival time of process %d: ", i + 1);
        scanf("%d %d",&processes[i].burst_time, &processes[i].arrival_time);
    }
    
    // Execute the processes
    execute_processes(processes, num_process, current_time);

    return 0;
}