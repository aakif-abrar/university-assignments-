#include <stdio.h>

int main()
{
	char name[20], cID[20];
	float units, charge, unitconsumed, supercharge, chargeb;
	printf("Enter Customer Name\n");
	scanf("%s", &name);
	printf("Enter Customer ID\n");
	scanf("%s", &cID);
	printf("Enter units consumed\n");
	scanf("%f", &units);
	if (units<199)
	{
		charge = units*16.2;
		unitconsumed = 16.2;
	}
	else if(units <300)
	{
		charge= units*20.10;
		unitconsumed = 20.10;
		
	}
	else if(units <500)
	{
		charge= units*27.10;
		unitconsumed = 27.10;
		
	}
	else
	{
		charge= units*35.90;
		unitconsumed = 35.90;
		
	}
	chargeb = charge;
	if(charge>18000)
	{
		supercharge = 0.15 * charge ;
		charge = charge *1.15;
	}
	printf("Customer ID :%s \nCustomer Name :%s \nUnits Consumed :%.2f\nAmount Charges :@Rs. %.2f per unit: %.2f \nSuper Charge amount :%.2f \nNet Amount Paid by the Customer: %.2f", cID, name, units, unitconsumed, chargeb, supercharge, charge);

	
	return 0;
}