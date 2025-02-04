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

// 2. Write a program in C to read n number of values in an array and display it in reverse order.
#include <stdio.h>

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array in reverse order: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

// 3. Write a C Program to find the minimum and maximum number in an array.
#include <stdio.h>

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int min = arr[0], max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    printf("Minimum Number = %d\n", min);
    printf("Maximum Number = %d\n", max);
    return 0;
}

// 4. Given an array arr[] of size N which contains elements from 0 to N-1, you need to find all the elements occurring more than once in the given array.
#include <stdio.h>

int main() {
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];
    int count[n];

    printf("Enter elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (count[i] > 1) {
            printf("Number %d occurs more than once.\n", i);
        }
    }

    return 0;
}
