#include<iostream>
using namespace std;

class Person {
public:
    virtual void getdata() {}
    virtual void displaydata() {}
    virtual void bonus() {}
};

class Admin : virtual public Person {
public:
    void getdata() {}
    void displaydata() {}
    void bonus() {}
};

class Account : virtual public Person {
public:
    void getdata() {}
    void displaydata() {}
    void bonus() {}
};

class Master : public Admin, public Account {
public:
    void getdata() {}
    void displaydata() {}
    void bonus() {}
};

int main() {
    Person* p;
    Master m;
    p = &m;
    p->getdata();
    p->displaydata();
    p->bonus();
}