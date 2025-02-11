#include <iostream>
#include <string>
using namespace std;
class Employee
{
private:
    string fname, lname;
    float msalary;

public:
    void setfname(string first)
    {
        fname = first;
    }
    void setlname(string last)
    {
        lname = last;
    }
    void setmsalary(float sal)
    {
        msalary = sal;
        if(msalary<0)
        {
            msalary=0;
        }
    }

    float getmsalary()
    {
        return msalary;
    }

    void display()
    {
        cout<<"Name: "<<fname<<" "<<lname<<endl;
        cout<<"Salary: "<<msalary<<endl;
    }
};
int main()
{
    Employee emp[2];
    string fname;
    string lname;
    float salary;
    for(int i=0;i<2;i++)
    {
        cout<<endl<<"First name: ";
        cin>>fname;
        cout<<"Last name: ";
        cin>>lname;
        cout<<"Salary: ";
        cin>>salary;
        emp[i].setfname(fname);
        emp[i].setlname(lname);
        emp[i].setmsalary(salary);
        cout<<endl;
    }
    for(int i=0;i<2;i++)
    {
        emp[i].display();
        cout<<"10% incremented: ";
        cout<<endl;
        emp[i].setmsalary(emp[i].getmsalary()*1.1);
        emp[i].display();
        cout<<endl;
        }

}
