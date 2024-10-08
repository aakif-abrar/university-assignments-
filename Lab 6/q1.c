//Which loop system would be better for user input. Justify your answer by creating a program 

//that takes a value and adds it to a variable and prints it repeatedly until the user enters a zero 

//value
#include <stdio.h>
int main() 
{
    int userinput, sum=0;
   
    do
    {
        printf("Enter a value \n");
        scanf("%d", &userinput);
        sum = sum + userinput;
        printf("The sum is %d\n",sum);
    }while(userinput != 0);   
        
    return 0;
}
