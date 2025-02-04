#include <iostream>
#include <vector>
using namespace std;
struct Subject {
    string subjectName;
};

struct Student {
    int ID;
    vector<Subject> subjects;
};

int main() {
    Subject maths={"Mathematics"};
    Subject eng={"English"};
    Subject phy={"Physics"};
    Subject pf={"Programming Fundamentals"};
    Student s1={1,{maths,eng}};
    Student s2={2,{phy,pf}};
    vector<Student> allStudents={s1,s2};
    for(int i=0;i<allStudents.size();i++)
    {
        cout<<"ID: "<<allStudents[i].ID<<endl;
        for(int j=0;j<allStudents[i].subjects.size();j++)
        {
            cout<<"Subject "<<i+1<<": "<<allStudents[i].subjects[j].subjectName<<endl;
        }
        cout<<endl;
    }
    return 0;
}
