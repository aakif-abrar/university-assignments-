#include<iostream>
using namespace std;
typedef struct
    {
        int emp_id;
        string name;
        float salary;
    }Employee;
    
typedef struct
{
    Employee emp;
    string org_num;
    string org_name;
}Organization;

int main()
{
    Organization org;
    org.org_name="NU-Fast";
    org.org_num="NUFAST123ABC";
    org.emp.emp_id=127;
    org.emp.name="Linus Sebastian";
    org.emp.salary=400000;
    cout<<"Size of structure oraganization: "<<sizeof(Organization)<<endl;
    cout<<"Organisation Name: "<<org.org_name<<endl;
    cout<<"Organisation Number: "<<org.org_num<<endl;
    cout<<"Employee Id: "<<org.emp.emp_id<<endl;
    cout<<"Employee Name: "<<org.emp.name<<endl;
    cout<<"Salary: "<<org.emp.salary<<endl;
}