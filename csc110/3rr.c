// round robin

#include <stdio.h>

typedef struct Process {
    int process_id;
    int burst_time;
} Process;

int main() {
    int num_process;
    int time_slice;

    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    printf("\n");

    Process processes[num_process];

    for (int i = 0; i < num_process; i++) {
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &processes[i].burst_time);
        processes[i].process_id = i;
    }
    
    printf("\nEnter the size of time slice: ");
    scanf("%d", &time_slice);

    int time_takes = 0;
    int avg_waiting_time = 0;
    int avg_turnaround_time = 0;

    int num_repetition = 0;

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    while (processes->burst_time != 0){
        for (int i = 0; i < num_process; i++) {
            if (processes[i].burst_time == 0) continue;
            printf("P%d\t\t", processes[i].process_id);

            if (processes[i].burst_time > time_slice) {
                printf("%d\t\t", time_slice);
                processes[i].burst_time = processes[i].burst_time - time_slice;

                printf("%d\t\t", time_takes);
                avg_waiting_time += time_takes;

                time_takes += time_slice;
                printf("%d\t\t", time_takes);
                avg_turnaround_time += time_takes;
            } else {
                printf("%d\t\t", processes[i].burst_time);
                printf("%d\t\t", time_takes);
                avg_waiting_time += time_takes;

                time_takes += processes[i].burst_time;
                printf("%d\t\t", time_takes);
                avg_turnaround_time += time_takes;

                processes[i].burst_time = 0;

            }
            
            num_repetition = num_repetition + 1;
            printf("\n");
        }
        // printf("\n---\n");
    }

    // printf("num_repetition: %d\n", num_repetition);
    printf("Average waiting time: %.5f\n", (float) avg_waiting_time / num_repetition);
    printf("Average turnaround time: %.5f\n", (float) avg_turnaround_time / num_repetition);


    return 0;
}