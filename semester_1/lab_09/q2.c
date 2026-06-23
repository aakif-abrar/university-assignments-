// 2. Program to swap two integers using a user-defined function, swapIntegers
#include <stdio.h>

void swapIntegers(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x, y;
    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);
    swapIntegers(&x, &y);
    printf("After swapping: %d %d\n", x, y);
    return 0;
}

