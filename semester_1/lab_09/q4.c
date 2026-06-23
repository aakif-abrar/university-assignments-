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

