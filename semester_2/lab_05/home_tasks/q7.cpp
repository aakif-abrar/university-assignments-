#include <iostream>
using namespace std;

class Student {
    const int roll_no;
public:
    Student(int r) : roll_no(r) {}
    void display() { cout << "Roll No: " << roll_no << endl; }
};

int main() {
    int r;
    cout << "Enter roll number: "; cin >> r;
    Student s(r);
    s.display();
    return 0;
}