#include <stdio.h>
int main()
{
	float cost;
	printf("Enter the cost of an item ");
	scanf("%f", &cost);

	if(cost >= 500 && cost < 2000)
	{
	printf("The actual amount: %.3f\nSaved amount: %.3f\nAmount after discount: %.3f", cost, cost*0.05, cost*0.95);
	}

	else if(cost >= 2000 && cost <= 4000)
	{
	printf("The actual amount: %.3f\nSaved amount: %.3f\nAmount after discount: %.3f", cost, cost*0.1, cost*0.9);
	}

	else if(cost > 4000 && cost <= 6000)
	{
	printf("The actual amount: %.3f\nSaved amount: %.3f\nAmount after discount: %.3f", cost, cost*0.2, cost*0.8);
	}

	else if(cost > 6000)
	{
	printf("The actual amount: %.3f\nSaved amount: %.3f\nAmount after discount: %.3f", cost, cost*0.35, cost*0.65);
	}

	else
	{
	printf("The actual amount: %.3f\nSaved amount: %.3f\nAmount after discount: %.3f", cost, cost*0, cost*1);
	}

	return 0;
}
