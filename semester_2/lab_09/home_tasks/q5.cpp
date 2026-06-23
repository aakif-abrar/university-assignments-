#include<iostream>
using namespace std;

class Shape {
public:
    virtual float getArea() = 0;
};

class Rectangle : public Shape {
    float width, height;
public:
    Rectangle(float w, float h) : width(w), height(h) {}
    float getArea() {
        return width * height;
    }
};

class Triangle : public Shape {
    float base, height;
public:
    Triangle(float b, float h) : base(b), height(h) {}
    float getArea() {
        return 0.5 * base * height;
    }
};

int main() {
    Rectangle r(10, 5);
    Triangle t(6, 4);
    cout << r.getArea() << endl;
    cout << t.getArea() << endl;
}