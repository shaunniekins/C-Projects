/**
A simple calculator program that allows the user to perform various arithmetic operations on two input numbers. The available operations include addition, subtraction, multiplication, division, remainder calculation, square root calculation, and exponentiation. The program takes input from the user, performs the selected operation, and then prompts for new input to continue the calculations. The code includes functions for each operation, along with a main function that controls the flow of the program.
*/

#include <stdio.h>
#include <math.h>

int inputNum();
void operationFunc();
void addition(int, int);
void subtraction(int, int);
void multiplication(int, int);
void division(int, int);
void remain(int, int);
void squareRoot(int, int);
void exponent(int, int);

int firstNum, secondNum;

int main() 
{
    inputNum();
    return 0;
}

int inputNum() 
{
    printf("Enter first number: ");
    scanf("%d", &firstNum);
    printf("Enter second number: ");
    scanf("%d", &secondNum);

    operationFunc();
    return 0;
}

void operationFunc() 
{
    int choice;

    printf("\n(1) addition \n(2) subtraction \n(3) multiplication \n(4) division \n(5) remainder \n(6) square root \n(7) exponent of the numbers \nChoose operation to use: (1 2 3 4 5 6 or 7) \n==> ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            addition(firstNum, secondNum);
            inputNum();
            break;

        case 2:
            subtraction(firstNum, secondNum);
            inputNum();
            break;

        case 3:
            multiplication(firstNum, secondNum);
            inputNum();
            break;
    
        case 4:
            division(firstNum, secondNum);
            inputNum();
            break;

        case 5:
            remain(firstNum, secondNum);
            inputNum();
            break;

        case 6:
            squareRoot(firstNum, secondNum);
            inputNum();
            break;
    
        case 7:
            exponent(firstNum, secondNum);
            inputNum();
            break;

        default:
            printf("Invalid choice. Please try again.\n");
            inputNum();
            break;
    }
}

void addition(int num1, int num2) 
{
    int sum = num1 + num2;
    printf("Sum: %d\n\n", sum);
}

void subtraction(int num1, int num2) 
{
    int diff = num1 - num2;
    printf("Difference: %d\n\n", diff);
}

void multiplication(int num1, int num2) 
{
    int product = num1 * num2;
    printf("Product: %d\n\n", product);
}

void division(int num1, int num2) 
{
    if (num2 == 0) 
    {
        printf("Error: Cannot divide by zero.\n\n");
        return;
    }

    int quotient = num1 / num2;
    printf("Quotient: %d\n\n", quotient);
}

void remain(int num1, int num2) 
{
    int rem = num1 % num2;
    printf("Remainder: %d\n\n", rem);
}

void squareRoot(int num1, int num2) 
{
    if (num1 < 0 || num2 < 0) 
    {
        printf("Error: Cannot calculate square root of a negative number.\n\n");
        return;
    }

    float sqrt1 = sqrt(num1);
    float sqrt2 = sqrt(num2);
    printf("Square root: %f & %f\n\n", sqrt1, sqrt2);
}

void exponent(int num1, int num2) 
{
    int exp = 1;
    
    for (int i = 0; i < num2; i++)
    {
        exp *= num1;
    }

    printf("Exponent: %d\n\n",exp);
}
