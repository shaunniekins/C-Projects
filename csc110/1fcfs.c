// first come, first serve

#include <stdio.h>

int main() {
    int num_process;
    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    printf("\n");

    int process[num_process];

    for (int i = 0; i < num_process; i++) {
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &process[i]);
    }

    //printing
    int waiting_time = 0;
    int turnaround_time = 0;
    int avg_waiting_time = 0;
    int avg_turnaround_time = 0;
    
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_process; i++) {
        printf("P%d\t\t", i);
        printf("%d\t\t", process[i]);

        printf("%d\t\t", waiting_time);
        avg_waiting_time += waiting_time;
        waiting_time += process[i];

        turnaround_time += process[i];
        avg_turnaround_time += turnaround_time;
        printf("%d\n", turnaround_time);

        printf("\n");
    }

    printf("Average waiting time: %.5f\n", (float) avg_waiting_time / num_process);
    printf("Average turnaround time: %.5f\n", (float) avg_turnaround_time / num_process);
}