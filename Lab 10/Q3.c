// Create a program with a constant that defines the maximum allowable temperature (in Celsius). Write a function to compare input temperatures and use a static variable to count how many times temperatures exceeded the limit.
#include <stdio.h>
#define MAX_TEMP 30
void checkTemperature(float temp) {
    static int exceedCount = 0;
    if (temp > MAX_TEMP) {
        exceedCount++;
        printf("Temperature exceeded! Count: %d\n", exceedCount);
    } else {
        printf("Temperature is within the limit.\n");
    }
}
int main() {
    checkTemperature(32);
    checkTemperature(28);
    checkTemperature(35);
    return 0;
}
