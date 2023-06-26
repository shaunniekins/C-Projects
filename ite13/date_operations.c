/**
A simple program that provides two functionalities: date conversion and calculation of the difference between two dates. It uses an interactive menu to allow the user to choose between the available options. 

In the `main()` function, the program displays a menu and prompts the user for their choice. Based on the selected option, it calls the corresponding function (`conversion()` or `difference()`) to perform the desired operation. The program continues to run until the user chooses to exit.

The `conversion()` function takes arrays representing the day, month, and year, along with the maximum value (number of dates) as input. It converts the entered dates into a specific format and displays them.

The `difference()` function calculates the difference between two dates provided by the user. It prompts for the dates, performs the necessary calculations, and displays the result in terms of years, months, and days.
**/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void conversion(int *, int *, int *, int *);
void difference(int *, int *, int *, int);

int main()
{
    int day[MAX], month[MAX], year[MAX], maxVal;
    char choice;

    do {
        printf("\n\nMenu:\n");
        printf("1. Convert date/s\n");
        printf("2. Calculate difference between two dates\n");
        printf("3. Exit\n");
        printf("Enter your choice (1-3): ");
        scanf(" %c", &choice);

        switch(choice)
        {
            case '1':
                system("clear");
                printf("How many dates would you like to enter (max of 10): ");
                scanf("%d", &maxVal);

                int i;
                for(i = 0; i < maxVal; i++)
                {
                    printf("Enter Date %d (in the format MM/DD/YYYY): ", i + 1);
                    scanf("%d/%d/%d", &month[i], &day[i], &year[i]);
                }
                printf("\n");

                conversion(day, month, year, &maxVal);
                break;

            case '2':
                system("clear");
                difference(day, month, year, maxVal); 
                break;

            case '3':
                system("clear");
                return 0;

            default:
                system("clear");
                printf("Invalid choice\n");
                return 0;
        }
        printf("\n");
    } while (choice != '3');

    return 0;
}

void conversion(int *day, int *month, int *year, int *max)
{
    printf("Dates converted: \n");

    int i;
    for(i = 0; i < *max; i++)
    {
        if(day[i] == 1 || day[i] == 11 || day[i] == 21 || day[i] == 31)
        {
            printf("%dst of ", day[i]);
        } 
        else if(day[i] == 2 || day[i] == 22) {
            printf("%dnd of ", day[i]);
        } 
        else if(day[i] == 3 || day[i] == 23) {
            printf("%drd of ", day[i]);
        } 
        else {
            printf("%dth of ", day[i]);
        }

        switch (month[i])
        {
            case 1:
                printf("January");
                break;

            case 2:
                printf("February");
                break;

            case 3:
                printf("March");
                break;

            case 4:
                printf("April");
                break;

            case 5:
                printf("May");
                break;

            case 6:
                printf("June");
                break;

            case 7:
                printf("July");
                break;

            case 8:
                printf("August");
                break;

            case 9:
                printf("September");
                break;

            case 10:
                printf("October");
                break;

            case 11:
                printf("November");
                break;

            case 12:
                printf("December");
                break;
        }
        
        printf(" %d\n", year[i]);
    }
}

void difference(int *day, int *month, int *year, int maxVal)
{
    int firstDiff, secondDiff;
    int totalDays, totalMonths, totalYears;

    printf("Enter the first date (in the format MM/DD/YYYY): ");
    scanf("%d/%d/%d", &month[maxVal], &day[maxVal], &year[maxVal]);
    printf("Enter the second date (in the format MM/DD/YYYY): ");
    scanf("%d/%d/%d", &month[maxVal + 1], &day[maxVal + 1], &year[maxVal + 1]);

    firstDiff = maxVal;
    secondDiff = maxVal + 1;

    totalDays = day[firstDiff] - day[secondDiff];
    totalMonths = month[firstDiff] - month[secondDiff];
    totalYears = year[firstDiff] - year[secondDiff];

    printf("%d/%d/%d - %d/%d/%d is %d year/s %d month/s %d day/s\n",
           day[firstDiff], month[firstDiff], year[firstDiff],
           day[secondDiff], month[secondDiff], year[secondDiff],
           totalDays, totalMonths, totalYears);
}
