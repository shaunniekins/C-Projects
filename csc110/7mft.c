#include <stdio.h>

int main() {
    int total_memory;
    int block_size;
    int num_processes;
    int available_block;
    int total_internal_fragmentation = 0;

    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &total_memory);

    printf("Enter the block size (in Bytes): ");
    scanf("%d", &block_size);

    printf("Enter the number of processes: ");
    scanf("%d", &num_processes);

    int process_memory[num_processes];

    for (int i = 0; i < num_processes; i++) {
        printf("Enter memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &process_memory[i]);
    }

    // printf("No. of Blocks available in memory: ");
    // scanf("%d", &available_block);
    available_block = total_memory / block_size;
    printf("No. of Blocks available in memory -- %d\n", available_block);

    // printf("\n\nPROCESS\t\tMEMORY-REQUIRED\t\tALLOCATED\t\tINTERNAL-FRAGMENTATION\n");
    printf("\n\nPROCESS\t\tMEMORY-REQUIRED\t\tALLOCATED\t\tINTERNAL-FRAGMENTATION\t\tREMAINING MEMORY\n");
    
    // remaining_memory is the external_fragmentation
    int remaining_memory = total_memory;
    int internal_fragmentation = 0;

    for (int i = 0; i < num_processes; i++) {
        if (available_block == 0) {
            printf("Memory is Full, Remaining Processes cannot be accommodated\n");
            break;
        }

        printf("%d\t\t", i + 1);
        printf("%d\t\t\t", process_memory[i]);

        if (block_size >= process_memory[i]) {
            printf("YES\t\t\t");

            internal_fragmentation = block_size - process_memory[i];
            // printf("%d\n", internal_fragmentation);
            printf("%d", internal_fragmentation);
            
            total_internal_fragmentation += internal_fragmentation;
            remaining_memory -= block_size;
            printf("\t\t\t\t%d\n", remaining_memory);
            available_block--;
        } else {
            printf("NO\t\t\t");
            printf("---\n");
            continue;
        }
    }

    printf("\nTotal Internal Fragmentation is %d\n", total_internal_fragmentation);
    printf("Total External Fragmentation is %d\n", remaining_memory);

    return 0;
}