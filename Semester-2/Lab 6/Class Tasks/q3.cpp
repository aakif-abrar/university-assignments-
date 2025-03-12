#include <iostream>
class Employee {
protected:
    int id;
    std::string name;
public:
    Employee(int i, std::string n) : id(i), name(n) {}
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder() = 0;
};

class IOrderPreparer {
public:
    virtual void prepareOrder() = 0;
};

class IBiller {
public:
    virtual void generateBill() = 0;
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, std::string n) : Employee(i, n) {}
    void takeOrder() override { std::cout << name << " is taking an order." << std::endl; }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, std::string n) : Employee(i, n) {}
    void prepareOrder() override { std::cout << name << " is preparing an order." << std::endl; }
};

int main() {
    Waiter w(1, "John");
    Chef c(2, "Mike");
    w.takeOrder();
    c.prepareOrder();
    return 0;
}