#include <iostream>
using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index is out of bounds.";
    }
};

template<typename T>
class SafeArray {
private:
    T* arr;
    int size;

public:
    SafeArray(int s) {
        size = s;
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }

    int getSize() {
        return size;
    }
};

int main() {
    SafeArray<int> arr(5);

    try {
        for (int i = 0; i < arr.getSize(); i++)
            arr[i] = i * 2;

        cout << "Array contents:\n";
        for (int i = 0; i < arr.getSize(); i++)
            cout << arr[i] << " ";
        cout << endl;

        cout << "Trying to access out-of-bounds element:\n";
        cout << arr[10] << endl;  // Should throw

    } catch (const ArrayIndexOutOfBounds& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
