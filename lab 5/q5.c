// 1. Write a program to swap two numbers using bitwise XOR.
#include <stdio.h>
int main() 
{
    int a = 3, b = 4;
    a = a ^ b; 
    b = a ^ b; 
    a = a ^ b;
    printf("%d %d", a, b);
    return 0;
    
}