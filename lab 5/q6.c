// Create a program that counts the number of 1s in the binary representation of a number.
#include <stdio.h>
int main()
{
	int num, count;
	printf("enter a number\n");
	scanf("%d", &num);
	count = 0;
	while(num>0)
	{
		if (num%2 == 1)
		{
			count++;
		}
		num = (num/2);
		
	}
	printf("the number of ones in the binary representation is %d ", count);
	return 0;
}