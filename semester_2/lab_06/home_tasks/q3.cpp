#include <iostream>
class Student {
protected:
    std::string name;
public:
    Student(std::string n) : name(n) {}
    void displayInfo() { std::cout << "Student Name: " << name << std::endl; }
};

class Marks : public Student {
protected:
    int math, science;
public:
    Marks(std::string n, int m, int s) : Student(n), math(m), science(s) {}
    void displayMarks() { std::cout << "Math: " << math << ", Science: " << science << std::endl; }
};

class Result : public Marks {
public:
    Result(std::string n, int m, int s) : Marks(n, m, s) {}
    void displayResult() {
        int total = math + science;
        double avg = total / 2.0;
        displayInfo();
        displayMarks();
        std::cout << "Total: " << total << ", Average: " << avg << std::endl;
    }
};

int main() {
    Result r("Alice", 90, 85);
    r.displayResult();
    return 0;
}