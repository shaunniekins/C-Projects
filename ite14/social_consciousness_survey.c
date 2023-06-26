/**
A program that allows the user to rate social-consciousness issues on a scale of 1 to 10. It uses arrays to store the topics and the responses for each issue. The program provides a menu to display all responses or display responses for a specific issue. The user can exit the program as well.
**/

#include <stdio.h>
#define NUM_ISSUES 5
#define RESPONSE_SCALE 10

int main() {
    char *topics[NUM_ISSUES] = {"Climate Change", "Racial Equality", "Gender Equality", "Income Inequality", "Healthcare Access"};
    int responses[NUM_ISSUES][RESPONSE_SCALE] = {0};
    int choice, issue_choice, rating;

    do {
        printf("Rate the following social-consciousness issues on a scale from 1 (least important) to 10 (most important):\n");
        for (int i = 0; i < NUM_ISSUES; i++) {
            printf("%d. %s: ", i+1, topics[i]);
            scanf("%d", &rating);
            if (rating < 1 || rating > 10) {
                printf("Invalid rating. Please enter a rating between 1 and 10.\n");
                i--;
                continue;
            }
            responses[i][rating-1]++;
        }

        printf("What would you like to do?\n");
        printf("1. Display responses for all issues\n");
        printf("2. Display responses for a specific issue\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("%-20s", "");
                for (int i = 1; i <= RESPONSE_SCALE; i++) {
                    printf("%-6d", i);
                }
                printf("\n");

                for (int i = 0; i < NUM_ISSUES; i++) {
                    printf("%-20s", topics[i]);
                    for (int j = 0; j < RESPONSE_SCALE; j++) {
                        printf("%-6d", responses[i][j]);
                    }
                    printf("\n");
                }
                break;
            case 2:
                printf("Which issue would you like to see responses for? (Enter 1-%d)\n", NUM_ISSUES);
                scanf("%d", &issue_choice);
                if (issue_choice < 1 || issue_choice > NUM_ISSUES) {
                    printf("Invalid issue choice. Please enter a number between 1 and %d.\n", NUM_ISSUES);
                    break;
                }
                printf("Summary of responses for %s:\n", topics[issue_choice-1]);
                printf("%-6s %-6s\n", "Rating", "Count");
                for (int i = 0; i < RESPONSE_SCALE; i++) {
                    printf("%-6d %-6d\n", i+1, responses[issue_choice-1][i]);
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }

    } while (choice != 3);

    return 0;
}
