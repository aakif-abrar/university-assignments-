//1. Write a program that checks if a year is a leap year using the modulus operator.
#include <stdio.h>
int main()
{
	int year;
	printf("enter a year\n");
	scanf("%d", &year);
	((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))? printf("Leap year!\n") : printf("not a leap year\n"); 
	return 0;
}