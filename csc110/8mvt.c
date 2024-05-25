#include <stdio.h>

int main() {
    int totalMemory;
    char confirmContinue = 'y';
    int processMemory[10]; 
    int i = 0;
    int usedMemory = 0;
    int totalMemoryAllocated = 0;

    printf("Enter the total memory available (in Bytes): ");
    scanf("%d", &totalMemory);

    while (usedMemory < totalMemory && confirmContinue == 'y') { 
        printf("Enter the memory required for process %d (in Bytes): ", i + 1);
        scanf("%d", &processMemory[i]);

        usedMemory += processMemory[i];
        if (usedMemory > totalMemory) {
            printf("Memory is full.");
            break;
        }

        if (usedMemory == totalMemory) {
            i++;
            break;
        };

        printf("Memory is allocated for Process %d\n", i + 1);
        do {
            printf("Do you want to continue (y/n): ");
            scanf(" %c", &confirmContinue);
        } while(confirmContinue != 'y' && confirmContinue != 'n');
        i++;
    }

    printf("Total Memory Available: %d", totalMemory);
    printf("\n\nPROCESS\t\tMEMORY-ALLOCATED (in Bytes)\n");
    for (int j = 0; j < i; j++) {
        printf("Process %d\t\t%d\n", j + 1, processMemory[j]);
        totalMemoryAllocated += processMemory[j];
    }
    printf("Total Memory Allocated is %d\n", totalMemoryAllocated);
    printf("Total External Fragmentation is %d\n", totalMemory - totalMemoryAllocated);

    return 0;
}