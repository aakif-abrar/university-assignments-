#include <iostream>
using namespace std;

class Shape {
    float area;
public:
    Shape(float a) : area(a) {}
    float Area() const {
        return area;
    }
    Shape operator+(const Shape& s) {
        return Shape(area + s.area);
    }
};