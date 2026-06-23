Qs5.
#include <stdio.h>
int main() {
float simpleinterest,principle,rate,period;
printf("Enter Principle between 100 to 1000000\n");
scanf("%f",&principle);
printf("Enter Rate between 5% to 10%\n");
scanf("%f",&rate);
printf("Enter Period between 1 year to 10 years\n");
scanf("%f",&period);
simpleinterest=principle*rate/100 *period;
printf("Simple Interest is %f",simpleinterest);
     return 0;
}
 
