// Write a program that checks if a number is divisible by both 3 and 5 using logical operators.
#include <stdio.h>
int main()
{
    int num, val;
    printf("Enter a number\n");
    val = scanf("%d", &num);
    while(getchar() != '\n');
    while(val != 1)
    {
        printf("enter a valid number\n");
        val = scanf("%d", &num);
        while(getchar() != '\n');
    }
    if(num%3 == 0 && num%5 == 0)
    {
        printf("The number is divisible by both 3 and 5\n");
    }
    else if(num%3 ==0)
    {
        printf("The number is divisible by 3 only\n");
    }
    else if(num%5 == 0)
    {
        printf("The number is divisible by 5 only\n");
    }
    else
    {
        printf("the number is not divisible by either 3 or 5");
    }
    return 0;
}