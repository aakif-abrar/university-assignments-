// Write a program to check whether a given number is a multiple digit number or not.

//1. Example: 123 is a multiple digit number.

//2. 6 is not a multiple digit number.
#include <stdio.h>
int main()
{
    int userinput;
    printf("Enter a number\n");
    scanf("%d", &userinput);
    if(userinput >=10)
    {
        printf ("%d is a multiple digit number", userinput);
    }
    else
    {
        printf("%d is a single digit number", userinput);
    }
    return 0;
}
