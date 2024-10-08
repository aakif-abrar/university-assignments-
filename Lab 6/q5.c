#include<stdio.h>

int main()
{
    int num = 65536,i=2;
    while(num > 0)
    {
        printf("%d ", num);
        num = num/i++;
    }
    return 0;
}
