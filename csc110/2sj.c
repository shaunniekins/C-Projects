// shortest job

#include <stdio.h>

void sort(int process[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (process[j] > process[j + 1]) {
                int temp = process[j];

                process[j] = process[j + 1];
                process[j + 1] = temp;
            }
        }
    }
}

int main() {
    int num_process;
    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    printf("\n");

    int origProcess[num_process];   // unsorted
    int process[num_process];       // sorted

    for (int i = 0; i < num_process; i++) {
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &process[i]);
        origProcess[i] = process[i];
    }

    sort(process, num_process);

    //printing
    int waiting_time = 0;
    int turnaround_time = 0;
    int avg_waiting_time = 0;
    int avg_turnaround_time = 0;
    
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num_process; i++) {
        for (int j = 0; j < num_process; j++) {
            if (process[i] == origProcess[j]) {
                printf("P%d\t\t", j);
                break;
            }
        }

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

    return 0;
}