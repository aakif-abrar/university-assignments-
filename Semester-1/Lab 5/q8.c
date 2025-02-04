//Create a program that calculates the sum of digits of a number until the result is a single digit
//(e.g., 123 -> 6)
#include <stdio.h>
int main()
{
	int num, sum = 0;
	printf("enter a number \n");
	scanf("%d", &num);
	do
	{
		if(sum>9)
		{
			num = sum;
			sum = 0;
		}
		while(num>0)
		{
			sum = sum + num%10;
			num = num/10;
		}
	}while(sum >9);	
	printf("sum is %d", sum);
	return 0;
}