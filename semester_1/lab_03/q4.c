Qs4.
#include <stdio.h>
 int main() {
 float distanceAB=1207.0,fuelpriceforward=118.0;
 float fuelpricereturn=123.0;
 float totaldistance,fuelavg,totallitresconsumed;
 float litresconsumedforward,litresconsumedreturn,forwardcost;
 float returncost,totalfuelcost;
 printf("Enter fuel average as a positive integer");
 scanf("%f",&fuelavg);
 totaldistance=distanceAB*2;
 totallitresconsumed=totaldistance/fuelavg;
 printf("Total fuel consumed is %2f",totallitresconsumed);
 litresconsumedforward=distanceAB/fuelavg;
 forwardcost=litresconsumedforward*118.0;
 litresconsumedreturn=distanceAB/fuelavg;
 returncost=litresconsumedreturn*123.0;
 totalfuelcost=forwardcost+returncost;
 printf("Total fuel cost is %2f",totalfuelcost);
      return 0;
}
 
