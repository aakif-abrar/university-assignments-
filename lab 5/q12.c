#include <stdio.h>

int main() {
    int age, creditScore;
    float income;

    printf("Enter your age: \n");
    scanf("%d", &age);

    printf("Enter your monthly income : \n");
    scanf("%f", &income);

    printf("Enter your credit score: \n");
    scanf("%d", &creditScore);

    if (age >= 18 && income >= 30000 && creditScore >= 650) {
        printf("You are eligible for the loan.\n");
    } else {
        printf("You are not eligible for the loan.\n");
    }

    return 0;
}
