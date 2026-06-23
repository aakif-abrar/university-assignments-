Qs6.
#include <stdio.h>
int main(){   
int x1,x2,y1,y2,gradient;
printf("Enter values \n");
scanf("%d",&x1);
scanf("%d",&x2);
scanf("%d",&y1);
scanf("%d",&y2);
gradient=y2-y1/x2-x1;
printf("Gradient is %d",gradient);
return 0;
}
 


