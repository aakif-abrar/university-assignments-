#include <iostream>

#include <string>

using namespace std;

class User

{

public:

    int Age;

    string Name;

    User()

    {

        Age = 24;

        Name = "Teo";

    }

};

int main()

{

    User u1;

    cout<<"My name is "<<u1.Name<<" and I'm "<<u1.Age<<" years old";

}
