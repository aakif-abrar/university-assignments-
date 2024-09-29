// Create a program that checks if a person is eligible to vote based on their age and citizenship status 
#include <stdio.h>
int main()
{
    float age;
    char citizenship[20];
    printf("enter your age\n");
    scanf("%f", &age);
    printf("Enter 'yes' if your are a citizen, 'no' if not\n");
    scanf("%s", citizenship);
    if(citizenship[0]=='y' && citizenship[1]=='e' && citizenship[2]=='s' && age >= 18)
    {
        printf("you can vote\n");
    }    
    else
    {
        printf("you can not vote\n");
    }
    return 0;
}