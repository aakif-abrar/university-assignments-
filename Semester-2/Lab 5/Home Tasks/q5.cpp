#include <iostream>
using namespace std;

class Car {
public:
    int engine_horsepower, seating_capacity, no_of_speakers;
    void setValues(int hp, int sc, int ns) const { const_cast<Car*>(this)->engine_horsepower = hp; const_cast<Car*>(this)->seating_capacity = sc; const_cast<Car*>(this)->no_of_speakers = ns; }
    void display() const { cout << engine_horsepower << " HP, " << seating_capacity << " seats, " << no_of_speakers << " speakers" << endl; }
};

int main() {
    Car myCar;
    myCar.setValues(200, 5, 6);
    myCar.display();
    return 0;
}