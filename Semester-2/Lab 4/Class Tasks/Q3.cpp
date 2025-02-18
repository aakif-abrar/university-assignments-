#include <iostream>
#include <stdexcept>

using namespace std;

class DynamicArray
{
private:
    int* arr;
    int arrSize;

public:
    DynamicArray() : arr(nullptr), arrSize(0) {}

    DynamicArray(int n) : arr(new int[n]()), arrSize(n) {}

    ~DynamicArray()
    {
        delete[] arr;
    }

    DynamicArray(const DynamicArray& other) : arr(new int[other.arrSize]), arrSize(other.arrSize)
    {
        for (int i = 0; i < arrSize; ++i)
        {
            arr[i] = other.arr[i];
        }
    }

    DynamicArray(DynamicArray&& other) noexcept : arr(other.arr), arrSize(other.arrSize)
    {
        other.arr = nullptr;
        other.arrSize = 0;
    }

    DynamicArray& operator=(const DynamicArray& other)
    {
        if (this != &other)
        {
            delete[] arr;
            arrSize = other.arrSize;
            arr = new int[arrSize];
            for (int i = 0; i < arrSize; ++i)
            {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other) noexcept
    {
        if (this != &other)
        {
            delete[] arr;
            arr = other.arr;
            arrSize = other.arrSize;
            other.arr = nullptr;
            other.arrSize = 0;
        }
        return *this;
    }

    int getSize() const
    {
        return arrSize;
    }

    int& at(int index)
    {
        if (index < 0 || index >= arrSize)
        {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    const int& at(int index) const
    {
        if (index < 0 || index >= arrSize)
        {
            throw out_of_range("Index out of range");
        }
        return arr[index];
    }

    void resize(int newSize)
    {
        if (newSize < 0)
        {
            throw invalid_argument("New size must be non-negative");
        }

        int* newArr = new int[newSize]();
        int minSize = (newSize < arrSize) ? newSize : arrSize;

        for (int i = 0; i < minSize; ++i)
        {
            newArr[i] = arr[i];
        }
        delete[] arr;
        arr = newArr;
        arrSize = newSize;
    }
};

int main()
{
    DynamicArray arr1(5);

    for (int i = 0; i < arr1.getSize(); ++i)
    {
        arr1.at(i) = i + 1;
    }

    cout << "Array 1: ";
    for (int i = 0; i < arr1.getSize(); ++i)
    {
        cout << arr1.at(i) << " ";
    }
    cout << endl;

    DynamicArray arr2 = arr1;
    cout << "Array 2 (copy of Array 1): ";
    for (int i = 0; i < arr2.getSize(); ++i)
    {
        cout << arr2.at(i) << " ";
    }
    cout << endl;

    arr2.resize(3);
    cout << "Array 2 after resizing: ";
    for (int i = 0; i < arr2.getSize(); ++i)
    {
        cout << arr2.at(i) << " ";
    }
    cout << endl;

    DynamicArray arr3 = std::move(arr1);
    cout << "Array 3 (moved from Array 1): ";
    for (int i = 0; i < arr3.getSize(); ++i)
    {
        cout << arr3.at(i) << " ";
    }
    cout << endl;

    return 0;
}
