// 1. Program to check if each word in a 2D array of strings is a palindrome
#include <stdio.h>
#include <string.h>

int isPalindrome(char word[]) {
    int len = strlen(word);
    for(int i = 0; i < len / 2; i++) {
        if(word[i] != word[len - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char words[5][20];
    for(int i = 0; i < 5; i++) {
        printf("Enter word %d: ", i + 1);
        scanf("%s", words[i]);
    }
    for(int i = 0; i < 5; i++) {
        if(isPalindrome(words[i])) {
            printf("%s: Palindrome\n", words[i]);
        } else {
            printf("%s: Not Palindrome\n", words[i]);
        }
    }
    return 0;
}

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

// 3. Program to check if a given integer is a prime number using a user-defined function
#include <stdio.h>

int isPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    if (isPrime(num)) {
        printf("%d is prime\n", num);
    } else {
        printf("%d is not prime\n", num);
    }
    return 0;
}

// 4. Program to perform basic arithmetic operations using a user-defined function calculate
#include <stdio.h>

float calculate(float a, float b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b != 0 ? a / b : 0;
        default: return 0;
    }
}

int main() {
    float num1, num2;
    char operation;
    printf("Enter two numbers: ");
    scanf("%f %f", &num1, &num2);
    printf("Enter operation (+, -, *, /): ");
    scanf(" %c", &operation);
    printf("Result: %.2f\n", calculate(num1, num2, operation));
    return 0;
}

// 5. Program to reverse a given string using a user-defined function and display the reversed string
#include <stdio.h>
#include <string.h>

void reverseString(char str[]) {
    int len = strlen(str);
    for(int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    reverseString(str);
    printf("Reversed string: %s\n", str);
    return 0;
}

// 6. Program to find the maximum and minimum elements in an integer array using a user-defined function
#include <stdio.h>

void findMaxMin(int arr[], int n, int *max, int *min) {
    *max = arr[0];
    *min = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > *max) *max = arr[i];
        if(arr[i] < *min) *min = arr[i];
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int max, min;
    findMaxMin(arr, n, &max, &min);
    printf("Maximum: %d, Minimum: %d\n", max, min);
    return 0;
}
