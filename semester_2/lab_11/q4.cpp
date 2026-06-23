#include <iostream>
using namespace std;

template<typename T>
class Base {
protected:
    T a, b;

public:
    Base(T x, T y) {
        a = x;
        b = y;
    }

    T multiply() {
        return a * b;
    }
};

template<typename T>
class Derived : public Base<T> {
private:
    T c, d;

public:
    Derived(T x, T y, T m, T n) : Base<T>(x, y) {
        c = m;
        d = n;
    }

    T multiplyDerived() {
        return c * d;
    }

    void printAllMultiplications() {
        cout << "Base multiplication: " << this->multiply() << endl;
        cout << "Derived multiplication: " << multiplyDerived() << endl;
    }
};

int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.printAllMultiplications();

    return 0;
}
