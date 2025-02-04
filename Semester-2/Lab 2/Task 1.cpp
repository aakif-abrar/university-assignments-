#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << *argv << " num1 num2 num3 ..." << endl;
        return 1;
    }
    int sum = 0;
    for (int i = 1; i < argc; i++)
        sum += atoi(*(argv+i));
    cout << "Sum of array elements: " << sum << endl;
    return 0;
}
