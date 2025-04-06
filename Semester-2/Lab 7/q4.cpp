#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i, string a, string p, string e) : name(n), id(i), address(a), phoneNumber(p), email(e) {}

    virtual void displayInfo() {
        cout << name << " " << id << " " << address << " " << phoneNumber << " " << email << endl;
    }

    virtual void updateInfo(string a, string p, string e) {
        address = a;
        phoneNumber = p;
        email = e;
    }
};

class Student : public Person {
    vector<string> coursesEnrolled;
    float GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string a, string p, string e, float g, int year)
        : Person(n, i, a, p, e), GPA(g), enrollmentYear(year) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "GPA: " << GPA << " Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
    string department;
    vector<string> coursesTaught;
    float salary;
public:
    Professor(string n, string i, string a, string p, string e, string d, float s)
        : Person(n, i, a, p, e), department(d), salary(s) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Dept: " << department << " Salary: " << salary << endl;
    }
};

class Staff : public Person {
    string department, position;
    float salary;
public:
    Staff(string n, string i, string a, string p, string e, string d, string pos, float s)
        : Person(n, i, a, p, e), department(d), position(pos), salary(s) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Dept: " << department << " Pos: " << position << " Salary: " << salary << endl;
    }
};

class Course {
    string courseId, courseName, instructor, schedule;
    int credits;
public:
    void registerStudent(Student& s) {}

    void calculateGrades() {}
};