// Create a C program that defines a constant for the conversion factor of meters to kilometers. Use a static variable in a function to count how many times the function is called.
#include <stdio.h>
#define M_TO_KM 0.001
void convertAndCount(float meters) {
    static int callCount = 0;
    callCount++;
    printf("%.2f meters = %.2f kilometers (Function called %d times)\n", meters, meters * M_TO_KM, callCount);
}
int main() {
    convertAndCount(1000);
    convertAndCount(500);
    return 0;
}
