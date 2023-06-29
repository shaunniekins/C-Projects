#include <stdio.h>

int main() {
    //Mara, Clara, Lara
    int ageMara, ageClara, ageLara;
    printf("Enter Mara's age: ");
    scanf("%d", &ageMara);
    printf("Enter Clara's age: ");
    scanf("%d", &ageClara);
    printf("Enter Lara's age: ");
    scanf("%d", &ageLara);

    if  (ageMara < ageClara && ageMara < ageLara) {
        printf("The youngest is Mara (%d).\n", ageMara);
        if (ageClara < ageLara) {
            printf("The middle child  is Clara (%d).\n", ageClara);
            printf("The eldest is Lara (%d).\n", ageLara);
        }
        if (ageLara < ageClara) {
            printf("The middle child  is Lara (%d).\n", ageLara);
            printf("The eldest is Clara (%d).\n", ageClara);
        }
        if (!(ageClara < ageLara || ageLara < ageClara)) {
            printf("Clara and Lara have the same age (%d)", ageClara);
        }
    }
    if (ageClara < ageMara && ageClara < ageLara) {
        printf("The youngest is Clara (%d).\n", ageClara);
        if  (ageMara < ageLara) {
            printf("The middle child is Mara (%d).\n", ageMara);
            printf("The eldest is Lara (%d).\n", ageLara);
        }
        if (ageLara < ageMara) {
            printf("The middle child  is Lara (%d).\n", ageLara);
            printf("The eldest is Mara (%d).\n", ageMara);
        }
    }
    if (ageLara < ageMara && ageLara < ageClara) {
        printf("The youngest is Lara (%d).\n", ageLara);
        if (ageMara < ageClara){
            printf("The middle child is Mara (%d).\n", ageMara);
            printf("The eldest is Clara (%d).\n", ageClara);
        }
        if (ageClara < ageMara) {
            printf("The middle child is Clara (%d).\n", ageClara);
            printf("The eldest is Mara (%d).\n", ageMara);
        }
    }
        
    return 0;
}