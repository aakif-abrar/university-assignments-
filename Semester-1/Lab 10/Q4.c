// Create a structure to store details about cars in a dealership, including make, model, year, price, and mileage. Write a program that allows users to add new cars, display a list of available cars, and search for cars by make or model.
#include <stdio.h>
#include <string.h>
typedef struct {
    char make[20], model[20];
    int year;
    float price, mileage;
} Car;
void displayCars(Car cars[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%s %s (%d) - $%.2f, %.2f km\n", cars[i].make, cars[i].model, cars[i].year, cars[i].price, cars[i].mileage);
    }
}
void searchCar(Car cars[], int count, char* key) {
    for (int i = 0; i < count; i++) {
        if (strstr(cars[i].make, key) || strstr(cars[i].model, key)) {
            printf("Found: %s %s (%d)\n", cars[i].make, cars[i].model, cars[i].year);
        }
    }
}
int main() {
    Car cars[10];
    int count = 0;
    strcpy(cars[count].make, "Toyota"); strcpy(cars[count].model, "Corolla"); cars[count].year = 2020; cars[count].price = 20000; cars[count++].mileage = 15000;
    displayCars(cars, count);
    searchCar(cars, count, "Toyota");
    return 0;
}
