// Write a recursive function linearSearch that takes an array, its size, the target element to search for, and the current index. It checks if the target is at the current index and continues searching in the subsequent indices until it either finds the target or exhausts the array.
#include <stdio.h>
int linearSearchRecursive(int arr[], int size, int target, int index) {
    if (index == size) return -1;
    if (arr[index] == target) return index;
    return linearSearchRecursive(arr, size, target, index + 1);
}
int main() {
    int arr[] = {5, 2, 9, 1, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 9;
    int result = linearSearchRecursive(arr, size, target, 0);
    printf("Element found at index: %d\n", result);
    return 0;
}
