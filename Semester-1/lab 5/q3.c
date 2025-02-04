// 1. Write a program using a ternary operator to find the maximum of two numbers.
#include <stdio.h>
int main()
{
    int num1, num2;
    printf("enter two numbers\n");
    scanf("%d %d", &num1, &num2);
    (num1>num2)? printf("first number is greater") :(num2>num1)? printf("second number is greater"):printf("both are equal");
    return 0;
}