#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Wallet {
    float balance;
    float dailyDepositLimit;
    float dailyWithdrawLimit;
    float depositedToday;
    float withdrawnToday;

public:
    Wallet(float depositLimit = 10000, float withdrawLimit = 5000)
        : balance(0), dailyDepositLimit(depositLimit), dailyWithdrawLimit(withdrawLimit),
          depositedToday(0), withdrawnToday(0) {}

    bool deposit(float amount) {
        if (amount > 0 && depositedToday + amount <= dailyDepositLimit) {
            balance += amount;
            depositedToday += amount;
            return true;
        }
        return false;
    }

    bool withdraw(float amount) {
        if (amount > 0 && amount <= balance && withdrawnToday + amount <= dailyWithdrawLimit) {
            balance -= amount;
            withdrawnToday += amount;
            return true;
        }
        return false;
    }

    float getBalance() const {
        return balance;
    }
};

class User {
    string userID;
    Wallet wallet;

public:
    User(string id) : userID(id) {}

    bool deposit(float amount) {
        return wallet.deposit(amount);
    }

    bool withdraw(float amount) {
        return wallet.withdraw(amount);
    }

    float checkBalance() const {
        return wallet.getBalance();
    }
};

int main() {
    User user1("U001");
    user1.deposit(3000);
    user1.withdraw(1000);
    cout << user1.checkBalance() << endl;

    User user2("U002");
    user2.deposit(12000);
    user2.withdraw(100);
    cout << user2.checkBalance() << endl;
}