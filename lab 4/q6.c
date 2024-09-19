#include <stdio.h>
int main()
{
	char num[10][10]= {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	int ui, val;
	printf("enter an integer from 0 to 9\n");
	val = scanf("%d", &ui);
	while(getchar() != '\n');
	while(val !=1 || ui>9 || ui<0)
	{
		printf("invalid integer! type again from 0 to 9\n");
		val = scanf("%d", &ui);
		while(getchar() != '\n');
		
	}
	printf("%s", num[ui]);
	
	return 0;
}