#include <stdio.h>

int main()
{
    int total_memory = 0, block_size = 0, num_processes = 0, block_available = 0;

    printf("Enter the total memory available--");
    scanf("%d", &total_memory);

    printf("Enter the block size--");
    scanf("%d", &block_size);

    printf("Enter the number of processes--");
    scanf("%d", &num_processes);

    int memory_array[num_processes];
    int allocated_array[num_processes];
    int internal_frag_array[num_processes];
    int i = 0;

    // user input for memory array
    for (i = 0; i < num_processes; i++)
    {
        printf("Enter memory required for Process %d: ", i + 1);
        scanf("%d", &memory_array[i]);
        allocated_array[i] = 0;
        internal_frag_array[i] = 0;
    }
    int blocks_available = 0, processed_memory = 0;
    block_available = total_memory / block_size;
    printf("No. of Blocks available in memory -- %d\n", block_available);

    printf("PROCESS\tMEMORY REQUIRED\tALLOCATED\tINTERNAL FRAGMENTATION\n");
    for (i = 0; i < num_processes; i++)
    {
        if (processed_memory >= block_available)
        {
            break;
        }
        if (memory_array[i] <= block_size)
        {
            allocated_array[i] = 1;
            internal_frag_array[i] = block_size - memory_array[i];
            processed_memory++;
        }
        printf("%d\t%d\t\t%d\t\t", i, memory_array[i], allocated_array[i]);
        if (memory_array[i] > block_size)
        {
            printf("--\n");
        }
        else
        {
            printf("%d\n", internal_frag_array[i]);
        }
    }
    if (processed_memory != num_processes)
    {
        printf("Memory is full, Remaining Processes cannot be accomodated.\n");
    }
    int total_internal_frag = 0;
    for (i = 0; i < processed_memory; i++)
    {
        total_internal_frag += internal_frag_array[i];
    }
    printf("Total Internal Fragmentation is %d\n", total_internal_frag);
    int external_frag = 0;
    external_frag = total_memory - (block_size * block_available);
    printf("Total External Fragmentation is %d\n", external_frag);

    return 0;
}
