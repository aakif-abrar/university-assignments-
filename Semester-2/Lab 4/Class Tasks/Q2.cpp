#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Polynomial
{
private:
    double* coefficient;
    int degree;

public:
    Polynomial() : degree(0) {
        coefficient = new double[1]{0};
    }

    Polynomial(int deg, double* coeffs) : degree(deg) {
        coefficient = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
            coefficient[i] = coeffs[i];
    }

    ~Polynomial() {
        delete[] coefficient;
    }

    Polynomial(const Polynomial& p2) : degree(p2.degree) {
        coefficient = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficient[i] = p2.coefficient[i];
        }
    }

    Polynomial(Polynomial&& p3) noexcept : degree(p3.degree), coefficient(p3.coefficient) {
        p3.degree = 0;
        p3.coefficient = nullptr;
    }

    int getDegree() const {
        return degree;
    }

    double evaluate(double x) const {
        double res = 0;
        for (int i = 0; i <= degree; i++) {
            res += coefficient[i] * pow(x, i);
        }
        return res;
    }

    Polynomial add(const Polynomial& p) const 
    {
        int maxDeg = max(degree, p.degree);
        double* newCoeff = new double[maxDeg + 1]();
    
        for (int i = 0; i <= maxDeg; ++i) 
        {
            if (i <= degree)
            newCoeff[i] += coefficient[i];
            if (i <= p.degree)
            newCoeff[i] += p.coefficient[i];
        }
    
        return Polynomial(maxDeg, newCoeff);
    }
    
    Polynomial multiply(const Polynomial& p) const
    {
        int newDeg = degree + p.degree;
        double* newCoeff = new double[newDeg + 1]();
    
        for (int i = 0; i <= degree; ++i)
        {
            for (int j = 0; j <= p.degree; ++j)
            {
                newCoeff[i + j] += coefficient[i] * p.coefficient[j];
            }
        }
    
        return Polynomial(newDeg, newCoeff);
    }
    
    void print() const
    {
        bool firstTerm = true;
        for (int i = degree; i >= 0; --i)
        {
            if (coefficient[i] != 0)
            {
                if (!firstTerm && coefficient[i] > 0) 
                cout << "+";
                if (i > 0) 
                {
                    cout << coefficient[i] << "x^" << i;
                }
                else
                {
                    cout << coefficient[i];
                }
                firstTerm = false;
            }
        }
        cout << endl;
    }
};

int main()
{
    double coeff1[] = {3, 2, 1};
    Polynomial p1(2, coeff1);

    double coeff2[] = {1, 0, -1};
    Polynomial p2(2, coeff2);

    cout << "Polynomial 1: ";
    p1.print();

    cout << "Polynomial 2: ";
    p2.print();

    cout << "Polynomial 1 evaluated at x = 2: " << p1.evaluate(2) << endl;

    Polynomial sum = p1.add(p2);
    cout << "Sum of Polynomials: ";
    sum.print();

    Polynomial product = p1.multiply(p2);
    cout << "Product of Polynomials: ";
    product.print();

    return 0;
}
