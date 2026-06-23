// 1. Write a C Program that takes a user input array and prints the sum of its elements.
#include <stdio.h>

int main() {
    int n, sum = 0;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    printf("Sum of elements: %d\n", sum);
    return 0;
}

