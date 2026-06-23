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
