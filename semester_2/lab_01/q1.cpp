
// 1. Write a program that finds the second highest number in a float type array of 20 elements using pointer.
#include <iostream>
using namespace std;

int main()
{
    int array[20];

    for (int i = 0; i < 20; i++)
    {
        cout << "Enter the value of the index: " << i << endl;
        cin >> *(array + i);
    }
    int highest = *(array), secondhighest = *(array);
    for (int i = 1; i < 20; i++)
    {
        if (*(array + i) > highest)
        {
            highest = *(array + i);
        }
        if (*(array + i) > secondhighest && *(array + i) < highest)
        {
            secondhighest = *(array + i);
        }
    }
    cout << "Highest Value: " << highest << "\nSecond Highest Value: " << secondhighest << endl;
    return 0;
}
