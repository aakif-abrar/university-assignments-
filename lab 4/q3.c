#include <stdio.h>
int main()
{
	char chr;
	printf("Enter a character \n");
	scanf(" %c", &chr);
	if(chr>='a' && chr<='z')
	{
	printf("It is a samll alphabet ");
	}
	else if(chr>='A' && chr<='Z')
	{
	printf("It is a Capital alphabet ");
	}
	else if(chr>='0' && chr<='9')
	{
	printf("It is a number");
	}
	else
	{
	printf("It is a special character");
	}
	return 0;
}
