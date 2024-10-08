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
        printf ("%d is a multiple digit number\n", userinput);
    }
    else
    {
        printf("%d is a single digit number\n", userinput);
    }
    
    // Using the above program integrate the number if it is a prime or composite number
    int prime = 1,i;
    for(i=2 ; i< ( (userinput/2)-userinput % 2 ) ; i++)
    {
        if(userinput % i ==0)
        {
            prime = 0;
        }
    }
    (prime ==0)? printf("%d is not prime number, it is a composite number", userinput) : printf("%d is a prime number", userinput);
    return 0;
}
