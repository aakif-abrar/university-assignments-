#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow: Cannot perform operation on empty stack.";
    }
};

template<typename T>
class Stack {
private:
    vector<T> items;

public:
    void push(T value) {
        items.push_back(value);
    }

    void pop() {
        if (items.empty())
            throw StackUnderflowException();
        items.pop_back();
    }

    T top() {
        if (items.empty())
            throw StackUnderflowException();
        return items.back();
    }

    bool isEmpty() {
        return items.empty();
    }
};

int main() {
    Stack<int> s;

    try {
        s.push(10);
        s.push(20);
        cout << "Top element: " << s.top() << endl;

        s.pop();
        s.pop();
        s.pop();  // This will throw exception
    } catch (const StackUnderflowException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
