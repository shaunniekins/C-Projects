/**
A word frequency counter program. It takes a sentence as input, converts it to lowercase, separates the words, and then counts the frequency of each word appearing in the sentence. The program displays the output, showing each word along with the number of times it appears in the sentence.
**/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lowerInputString(char *str, int len)
{
    int i = 0;
    for (; i < len; i++)
    {
        str[i] = tolower(str[i]);
    }
}

void stringSeparator(char *str, char wordStr[][100], int *space)
{
    int i = 0, j = 0, spacer = 0;
    for (; i < strlen(str); i++)
    {
        if ((str[i] == ' ') || ((str[i] == ',') && (str[i + 1] == ' ')) || (str[i] == '.'))
        {
            wordStr[spacer][j] = '\0';
            spacer++;
            if ((str[i] == ',') && (str[i + 1] == ' '))
                i++;
            j = 0;
        }
        else
            wordStr[spacer][j++] = str[i];
    }
    *space = spacer;
}

void duplicateSeparator(int space, char temp[][100], int *sepWords, char word[][100])
{
    int i, j, sepWorder = 0;
    for (i = 0; i <= space; i++)
    {
        for (j = 0; j <= space; j++)
        {
            if (i == j)
            {
                strcpy(temp[sepWorder], word[i]);
                sepWorder++;
                break;
            }
            else
            {
                if (strcmp(temp[j], word[i]) != 0)
                {
                    continue;
                }
                else
                    break;
            }
        }
    }
    *sepWords = sepWorder;
}

int main()
{
    int sepWords = 0, rep = 0, i = 0, j = 0, space = 0;
    char name[30];
    char input_str[100], word[100][100], temp[100][100];

    printf("Write a word search C program that counts the frequency of each word appearing in a sentence.\n\n");
    printf("------------------------------------------\n");

    printf("Input: ");
    scanf(" %[^\n]s", input_str);
    printf("\n");

    lowerInputString(input_str, sizeof(input_str));
    stringSeparator(input_str, word, &space);
    duplicateSeparator(space, temp, &sepWords, word);

    printf("Output:\n");

    // compare each word
    for (i = 0; i < sepWords; i++)
    {
        for (j = 0; j <= space; j++)
        {
            if (strcmp(temp[i], word[j]) == 0)
                rep++;
        }
        strcpy(name, temp[i]);
        name[0] = toupper(name[0]);
        printf("%s -> %d time/s\n", name, rep);
        rep = 0;
    }

    return 0;
}
