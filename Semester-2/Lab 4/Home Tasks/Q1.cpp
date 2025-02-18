#include<iostream>
#include<string>
#include<cmath>
#define PI 3.141529
using namespace std;
class Circle
{
    int radius;
    public:
    Circle(int r):radius(r){}
    float getArea()
    {
        return PI*radius*radius;
    }
    float getPerimeter()
    {
        return 2*PI*radius;
    }
};
int main()
{
    Circle c1(20.5);
    cout<<"Area: "<<c1.getArea()<<endl;
    cout<<"Perimeter: "<<c1.getPerimeter();
}
