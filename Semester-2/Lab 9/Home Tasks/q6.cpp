#include<iostream>
#include<string>
using namespace std;

class Car {
protected:
    string model;
    float price;
public:
    virtual void setPrice(float p) = 0;
    string getModel() { return model; }
    float getPrice() { return price; }
};

class Color : public Car {
public:
    void setPrice(float p) {
        price = p + 500;
    }
};

class Company : public Car {
public:
    void setPrice(float p) {
        price = p + 1000;
    }
};

int main() {
    Color c;
    Company comp;
    c.setPrice(10000);
    comp.setPrice(20000);
    cout << c.getPrice() << endl;
    cout << comp.getPrice() << endl;
}