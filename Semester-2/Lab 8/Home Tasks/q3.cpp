#include <iostream>
using namespace std;

class Person {
protected:
    int id;
public:
    void getData() {
        cin >> id;
    }
    void displayData() {
        cout << "ID: " << id << endl;
    }
};

class Admin : public Person {
    string name;
    float income;
public:
    void getData() {
        Person::getData();
        cin >> name >> income;
    }
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Income: " << income << endl;
        cout << "Bonus: " << income * 0.05 << endl;
    }
};

class Accounts : public Person {
    string name;
    float income;
public:
    void getData() {
        Person::getData();
        cin >> name >> income;
    }
    void displayData() {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Income: " << income << endl;
        cout << "Bonus: " << income * 0.05 << endl;
    }
};