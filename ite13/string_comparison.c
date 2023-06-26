/**
A program that compares multiple strings and identifies unique strings among them. It prompts the user to input four strings, splits them into individual words, and stores them in separate arrays. The program then compares each word in the first array with the words in the remaining arrays, keeping track of matching occurrences. Finally, it determines and prints the unique strings from each array. The code utilizes nested loops and the `strcmp` function for string comparison.
**/

#include <stdio.h>
#include <string.h>
#define row 100
#define col 100

void newArr(char *string, int *counter, char newStr[row][col])
{
    int len_of_string = strlen(string);
    int count = *counter;
    int j = 0;
    
    int i;
    for(i = 0; i<=len_of_string; i++)
    {
        if(string[i] == ' ' || string[i] == '\0'){
            newStr[count++][j] = '\0';
            j=0;
        }
        else{
            newStr[count][j++] = string[i];
        }
        
    }
    *counter = count;
}

int main()
{
    char str1[50], str2[50], str3[50], str4[50], ns1[row][col], ns2[row][col], ns3[row][col], ns4[row][col];
    int contr = 0, contr2 = 0, contr3 = 0, contr4 = 0;
    int j=0, j2=0, j3=0, j4=0;
    int s1_s2=0, s1_s3=0, s1_s4=0, s2_s1=0, s2_s3=0, s2_s4=0, s3_s1=0, s3_s2=0, s3_s4=0, s4_s1=0, s4_s2=0, s4_s3=0;
    int i=0, maxwords=0;

        printf("String1: ");
        gets(str1);

        printf("String2: ");
        gets(str2);

        printf("String3: ");
        gets(str3);

        printf("String4: ");
        gets(str4);

    newArr(str1, &contr, ns1);
    newArr(str2, &contr2, ns2);
    newArr(str3, &contr3, ns3);
    newArr(str4, &contr4, ns4);


    //determine sa  pinakdaghan na words sa string

    if(contr > contr2 && contr > contr3 && contr > contr4){
        maxwords=contr;
    }else{
        if(contr2 > contr3 && contr2 > contr4){
            maxwords=contr2;
        }else{
            if(contr3 > contr4){
                maxwords=contr3;
            }else{
                maxwords=contr4;
            }
        }
    }

    //This part of the program compares the 1st string with the other 3

    int comp2, comp3, comp4;
        for(i=0; i < contr; i++){
        for(j=0; j < maxwords; j++){
           comp2 = strcmp(ns1[i], ns2[j]);
           comp3 = strcmp(ns1[i], ns3[j]);
           comp4 = strcmp(ns1[i], ns4[j]);
            if(comp2 == 0){
                s1_s2++;
            }if(comp3 == 0){
                s1_s3++;
            }if(comp4 == 0){
                s1_s4++;
            }
        }
    }



    comp2=0, comp3=0, comp4=0;
        for(i=0; i < contr2; i++){
        for(j=0; j < maxwords; j++){
           comp2 = strcmp(ns2[i], ns1[j]);
           comp3 = strcmp(ns2[i], ns3[j]);
           comp4 = strcmp(ns2[i], ns4[j]);
            if(comp2 == 0){
                s2_s1++;
            }if(comp3 == 0){
                s2_s3++;
            }if(comp4 == 0){
                s2_s4++;
            }
        }
    }


   comp2=0, comp3=0, comp4=0;
        for(i=0; i < contr3; i++){
        for(j=0; j < maxwords; j++){
           comp2 = strcmp(ns3[i], ns1[j]);
           comp3 = strcmp(ns3[i], ns2[j]);
           comp4 = strcmp(ns3[i], ns4[j]);
            if(comp2 == 0){
                s3_s1++;
            }if(comp3 == 0){
                s3_s2++;
            }if(comp4 == 0){
                s3_s4++;
            }
        }
    }



   comp2=0, comp3=0, comp4=0;
        for(i=0; i < contr4; i++){
        for(j=0; j < maxwords; j++){
           comp2 = strcmp(ns4[i], ns1[j]);
           comp3 = strcmp(ns4[i], ns2[j]);
           comp4 = strcmp(ns4[i], ns3[j]);
            if(comp2 == 0){
                s4_s1++;
            }if(comp3 == 0){
                s4_s2++;
            }if(comp4 == 0){
                s4_s3++;
            }
        }
    }



    if(s1_s2 == 0 && s1_s3 == 0 && s1_s4 == 0){
        printf("\nThe unique string(s) are: ");
        for(i=0; i < contr; i++){// printing of string 1
            printf("%s ", ns1[i]);
        }
    }
    if(s2_s1 == 0 && s2_s3 == 0 && s2_s4 == 0){
        printf("The unique string(s) are: ");
        for(i=0; i < contr2; i++){
        printf("%s ", ns2[i]);
    }
    }
    if(s3_s1 == 0 && s3_s2 == 0 && s2_s4 == 0){
        printf("\nThe unique string(s) are: ");
        for(i=0; i < contr3; i++){
        printf("%s ", ns3[i]);
    }
    }
    if(s4_s1 == 0 && s4_s2 == 0 && s4_s3 == 0){
        printf("\nThe unique string(s) are: ");
        for(i=0; i < contr4; i++){
        printf("%s ", ns4[i]);
    }
    }

    return 0;
}