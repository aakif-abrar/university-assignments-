#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount, exchangeRate;
    string currencyCode, currencySymbol;
public:
    Currency(double amt, string code, string symbol, double rate = 1.0)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    virtual double convertTo(double targetRate) {
        return convertToBase() / targetRate;
    }

    virtual void displayCurrency() {
        cout << currencySymbol << amount << " (" << currencyCode << ")" << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", "$", 1.0) {}

    void displayCurrency() override {
        cout << "$" << amount << " (US Dollar)" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", "€", 1.2) {}

    void displayCurrency() override {
        cout << "€" << amount << " (Euro)" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "PKR", "Rs", 0.006) {}

    void displayCurrency() override {
        cout << "Rs" << amount << " (Rupee)" << endl;
    }
};