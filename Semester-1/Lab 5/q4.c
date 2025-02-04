// 2. Use the ternary operator to check if a number is positive, negative, or zero.
#include <stdio.h>
int main()
{
    int num;
    printf("enter a number \n");
    scanf("%d", &num);
    char *result =(num>0)?"positive" : (num<0)? "negative" : "Zero";
    printf("%s",result);
    return 0;
}  