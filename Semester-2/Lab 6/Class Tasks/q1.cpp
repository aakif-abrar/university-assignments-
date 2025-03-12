#include <iostream>
#include <vector>

class BankAccount {
protected:
    std::string accountNumber;
    double balance;
public:
    BankAccount(std::string accNum, double bal) : accountNumber(accNum), balance(bal) {}
    virtual void deposit(double amount) { balance += amount; }
    virtual void withdraw(double amount) { if (balance >= amount) balance -= amount; }
    virtual void display() const { std::cout << "Account: " << accountNumber << " Balance: " << balance << std::endl; }
    virtual ~BankAccount() {}
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(std::string accNum, double bal) : BankAccount(accNum, bal) {}
    void applyInterest() { balance *= 1.05; }
};

class CheckingAccount : public BankAccount {
public:
    CheckingAccount(std::string accNum, double bal) : BankAccount(accNum, bal) {}
    void withdraw(double amount) override {
        if (balance - amount < 0) std::cout << "Overdraft alert!" << std::endl;
        else balance -= amount;
    }
};

int main() {
    BankAccount *acc1 = new SavingsAccount("SA123", 1000);
    BankAccount *acc2 = new CheckingAccount("CA456", 500);
    acc1->deposit(200);
    acc1->display();
    acc2->withdraw(600);
    acc2->display();
    delete acc1;
    delete acc2;
    return 0;
}
