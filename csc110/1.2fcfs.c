// linked-list implementation of first-come-first-serve scheduling algorithm

#include <stdio.h>
#include <stdlib.h>

struct Process {
    int burst_time;
    struct Process *next;
};

int main() {
    int num_process;
    printf("Enter the number of processes: ");
    scanf("%d", &num_process);
    printf("\n");

    struct Process *head = NULL;
    struct Process *tail = NULL;

    for (int i = 0; i < num_process; i++) {
        struct Process *new_process = malloc(sizeof(struct Process));
        printf("Enter the burst time for process %d: ", i);
        scanf("%d", &new_process->burst_time);
        new_process->next = NULL;

        if (head == NULL) {
            head = new_process;
            tail = new_process;
        } else {
            tail->next = new_process;
            tail = new_process;
        }
    }

    //printing
    int waiting_time = 0;
    int turnaround_time = 0;
    int avg_waiting_time = 0;
    int avg_turnaround_time = 0;
    
    printf("\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n");
    struct Process *current = head;
    for (int i = 0; i < num_process; i++) {
        printf("P%d\t\t", i);
        printf("%d\t\t", current->burst_time);

        printf("%d\t\t", waiting_time);
        avg_waiting_time += waiting_time;
        waiting_time += current->burst_time;

        turnaround_time += current->burst_time;
        avg_turnaround_time += turnaround_time;
        printf("%d\n", turnaround_time);

        printf("\n");

        current = current->next;
    }

    printf("Average waiting time: %.5f\n", (float) avg_waiting_time / num_process);
    printf("Average turnaround time: %.5f\n", (float) avg_turnaround_time / num_process);

    // Free the memory allocated for the linked list
    while (head != NULL) {
        struct Process *temp = head;
        head = head->next;
        free(temp);
    }
}