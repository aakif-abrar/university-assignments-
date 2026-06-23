// Design a structure to store information about travel packages, including package name, destination, duration, cost, and number of seats available. Write a program that allows users to book a travel package and display available packages.
#include <stdio.h>
#include <string.h>
typedef struct {
    char name[30], destination[30];
    int duration, seats;
    float cost;
} Package;
void displayPackages(Package packages[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s to %s: %d days, $%.2f, %d seats available\n", packages[i].name, packages[i].destination, packages[i].duration, packages[i].cost, packages[i].seats);
    }
}
int main() {
    Package packages[2] = {{"Summer Escape", "Maldives", 5, 1200, 10}, {"Winter Retreat", "Switzerland", 7, 1500, 5}};
    displayPackages(packages, 2);
    return 0;
}
