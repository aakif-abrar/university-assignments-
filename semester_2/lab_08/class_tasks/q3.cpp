#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
    vector<int> digits;
    bool isNegative;

public:
    BigInteger() : isNegative(false) {}

    BigInteger(string number) {
        isNegative = (number[0] == '-');
        for (int i = number.length() - 1; i >= isNegative; --i)
            digits.push_back(number[i] - '0');
    }

    BigInteger operator+(const BigInteger& other) {
        BigInteger result;
        int carry = 0, i = 0;
        while (i < digits.size() || i < other.digits.size() || carry) {
            int sum = carry;
            if (i < digits.size()) sum += digits[i];
            if (i < other.digits.size()) sum += other.digits[i];
            result.digits.push_back(sum % 10);
            carry = sum / 10;
            ++i;
        }
        return result;
    }

    friend ostream& operator<<(ostream& os, const BigInteger& b) {
        if (b.digits.empty()) return os << "0";
        if (b.isNegative) os << "-";
        for (int i = b.digits.size() - 1; i >= 0; --i)
            os << b.digits[i];
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& b) {
        string s;
        is >> s;
        b = BigInteger(s);
        return is;
    }
};