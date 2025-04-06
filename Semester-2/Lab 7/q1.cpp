#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNumber, accountHolderName, accountType;
    double balance;
public:
    Account(string num, string name, double bal, string type = "General")
        : accountNumber(num), accountHolderName(name), balance(bal), accountType(type) {}

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
    }

    virtual void calculateInterest() {}

    virtual void printStatement() {}

    virtual void getAccountInfo() {
        cout << "Account Number: " << accountNumber << "\nName: " << accountHolderName << "\nBalance: " << balance << "\nType: " << accountType << endl;
    }
};

class SavingsAccount : public Account {
    double interestRate, minimumBalance;
public:
    SavingsAccount(string num, string name, double bal, double rate, double minBal)
        : Account(num, name, bal, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override {
        balance += balance * interestRate;
    }

    void withdraw(double amount) override {
        if (balance - amount >= minimumBalance)
            balance -= amount;
    }

    void printStatement() override {
        cout << "Savings Account Statement for " << accountHolderName << "\nBalance: " << balance << endl;
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(string num, string name, double bal)
        : Account(num, name, bal, "Checking") {}

    void calculateInterest() override {}

    void printStatement() override {
        cout << "Checking Account Statement for " << accountHolderName << "\nBalance: " << balance << endl;
    }
};

class FixedDepositAccount : public Account {
    string maturityDate;
    double fixedInterestRate;
public:
    FixedDepositAccount(string num, string name, double bal, string mDate, double rate)
        : Account(num, name, bal, "Fixed Deposit"), maturityDate(mDate), fixedInterestRate(rate) {}

    void calculateInterest() override {
        balance += balance * fixedInterestRate;
    }

    void printStatement() override {
        cout << "Fixed Deposit Account Statement for " << accountHolderName << "\nMaturity Date: " << maturityDate << "\nBalance: " << balance << endl;
    }
};