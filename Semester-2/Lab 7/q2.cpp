#include <iostream>
#include <cmath>
using namespace std;

class Shape {
protected:
    string position, color;
    double borderThickness;
public:
    Shape(string pos, string col, double border = 1.0) : position(pos), color(col), borderThickness(border) {}

    virtual void draw() {}

    virtual double calculateArea() { return 0; }

    virtual double calculatePerimeter() { return 0; }
};

class Circle : public Shape {
    double radius;
public:
    Circle(string pos, string col, double r) : Shape(pos, col), radius(r) {}

    void draw() override {}

    double calculateArea() override {
        return 3.1416 * radius * radius;
    }

    double calculatePerimeter() override {
        return 2 * 3.1416 * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(string pos, string col, double w, double h) : Shape(pos, col), width(w), height(h) {}

    void draw() override {}

    double calculateArea() override {
        return width * height;
    }

    double calculatePerimeter() override {
        return 2 * (width + height);
    }
};

class Triangle : public Shape {
    double a, b, c;
public:
    Triangle(string pos, string col, double side1, double side2, double side3) : Shape(pos, col), a(side1), b(side2), c(side3) {}

    void draw() override {}

    double calculateArea() override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }

    double calculatePerimeter() override {
        return a + b + c;
    }
};