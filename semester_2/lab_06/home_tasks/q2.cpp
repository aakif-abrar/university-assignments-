#include <iostream>
class Vehicles {
protected:
    double price;
public:
    Vehicles(double p) : price(p) {}
};

class Car : public Vehicles {
protected:
    int seatingCapacity, doors;
    std::string fuelType;
public:
    Car(double p, int s, int d, std::string f) : Vehicles(p), seatingCapacity(s), doors(d), fuelType(f) {}
};

class Audi : public Car {
    std::string model;
public:
    Audi(double p, int s, int d, std::string f, std::string m) : Car(p, s, d, f), model(m) {}
    void display() {
        std::cout << "Audi Car - Price: " << price << ", Seats: " << seatingCapacity << ", Doors: " << doors << ", Fuel: " << fuelType << ", Model: " << model << std::endl;
    }
};

int main() {
    Audi a(50000, 5, 4, "Petrol", "A6");
    a.display();
    return 0;
}