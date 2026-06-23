
// Write a program to print the following series: 1, 2, 3, 5, 8, 13.
#include<stdio.h>

int main()
{
    int n,i, previous = 1, current=2,temp;
    printf("Enter the value of n\n");
    scanf("%d", &n);
    (n>=1)? printf("1 ") : 0;
    (n>=2)? printf("2 ") : 0;
    if(n>=3)
    {
        for(i=0 ; i<n-2 ; i++)
        {
            temp = previous;
            previous= current;
            current= current+ temp ;
            printf("%d ", current);
        }
    }    
    return 0;
}
