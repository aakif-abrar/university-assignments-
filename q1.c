#include <stdio.h>
int main()
{
	int num, intvalidation;
	printf("Enter a number \n");
	intvalidation = scanf("%d", &num );
	while(getchar() != '\n');
	while(intvalidation!=1)
	{
		printf("please enter a valid integer \n");
		intvalidation = scanf("%d", &num);
		while(getchar() != '\n');
		
	}
	if(num%3== 0 )	
	{
		printf("The number is a multiple of 3 ");
	}
	else
	{
		printf("The number is not a multiple of 3 ");
	}
	return 0;
}
