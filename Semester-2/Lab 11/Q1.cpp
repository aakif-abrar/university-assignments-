#include <iostream>
#include <any>
#include <string>
using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Incorrect type requested.";
    }
};

class TypeSafeContainer {
private:
    any value;

public:
    template<typename T>
    void store(T v) {
        value = v;
    }

    template<typename T>
    T get() {
        if (!value.has_value())
            throw BadTypeException();

        try {
            return any_cast<T>(value);
        } catch (const bad_any_cast&) {
            throw BadTypeException();
        }
    }
};

int main() {
    TypeSafeContainer container;

    try {
        container.store<int>(100);
        cout << "Stored int: " << container.get<int>() << endl;

        container.store<string>("Hello");
        cout << "Stored string: " << container.get<string>() << endl;

        cout << "Trying wrong type: " << container.get<int>() << endl; // Should throw
    } catch (const BadTypeException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
