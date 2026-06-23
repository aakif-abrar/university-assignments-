#include <iostream>
#include <vector>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial& p, int x);
    static Polynomial derivative(const Polynomial& p);
};

class Polynomial {
    vector<int> coeffs;

    void trim() {
        while (!coeffs.empty() && coeffs.back() == 0) coeffs.pop_back();
    }

public:
    Polynomial() {}
    Polynomial(vector<int> c) : coeffs(c) { trim(); }

    Polynomial operator+(const Polynomial& other) {
        vector<int> result(max(coeffs.size(), other.coeffs.size()));
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] += other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator-(const Polynomial& other) {
        vector<int> result(max(coeffs.size(), other.coeffs.size()));
        for (size_t i = 0; i < coeffs.size(); ++i) result[i] += coeffs[i];
        for (size_t i = 0; i < other.coeffs.size(); ++i) result[i] -= other.coeffs[i];
        return Polynomial(result);
    }

    Polynomial operator*(const Polynomial& other) {
        vector<int> result(coeffs.size() + other.coeffs.size() - 1, 0);
        for (size_t i = 0; i < coeffs.size(); ++i)
            for (size_t j = 0; j < other.coeffs.size(); ++j)
                result[i + j] += coeffs[i] * other.coeffs[j];
        return Polynomial(result);
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        for (int i = p.coeffs.size() - 1; i >= 0; --i) {
            if (p.coeffs[i]) {
                if (i != (int)p.coeffs.size() - 1 && p.coeffs[i] > 0) os << "+";
                if (i == 0 || p.coeffs[i] != 1) os << p.coeffs[i];
                if (i > 0) os << "x";
                if (i > 1) os << "^" << i;
            }
        }
        return os;
    }

    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial& p, int x) {
    int result = 0, power = 1;
    for (int coeff : p.coeffs) {
        result += coeff * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial& p) {
    vector<int> result;
    for (size_t i = 1; i < p.coeffs.size(); ++i)
        result.push_back(p.coeffs[i] * i);
    return Polynomial(result);
}