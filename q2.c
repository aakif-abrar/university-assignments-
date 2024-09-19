#include <stdio.h>
int main()
{
	float num1, num2;
	int val, operatorval;
	char operator;
	

	printf(" Enter first number \n");
	val = scanf("%f" , &num1);
	while(getchar() != '\n');
	while(val !=1)
	{
		printf(" invalid number!! Enter a valid first number \n");
		val = scanf("%f" , &num1);
		while(getchar() != '\n');
	}
	

	printf(" Enter an operator '+' or '-' or '*' or '/'   \n");
	val = scanf(" %c", &operator);
	while(getchar() != '\n');
	operatorval = 0;
	if (operator == '+' || operator == '-' || operator =='*' || operator =='/')
	{
		operatorval = 1;
		}
		
	while(val !=1 || operatorval!=1)
	{
		printf(" invalid operator!! Enter a operator '+' or '-' or '*' or '/'  \n");
		val = scanf(" %c" , &operator);
		while(getchar() != '\n');
		operatorval = 0;
		if(operator == '+' || operator == '-' || operator =='*' || operator =='/')
		{
			operatorval = 1;
		}
	}

	printf(" Enter the second number\n");
	val = scanf("%f" , &num2);
	while(getchar() != '\n');
	while(val != 1)
	{
		printf("Invalid second number!!! Enter a valid second number \n");
		val = scanf("%f",&num2);
		while(getchar() != '\n');
	}
	switch(operator)
	{
		case '+': 
			printf("%.2f", num1+num2);
			break;
		case '-': 
			printf("%.2f", num1-num2);
			break;
		case '*': 
			printf("%.2f", num1*num2);
			break;
		case '/': 
			printf("%.2f", num1/num2);
			break;
		
	}
	return 0;
}
