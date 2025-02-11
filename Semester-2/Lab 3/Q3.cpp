#include <iostream>
#include <string>
using namespace std;
class  Date
{
private:
    int day,month,year;
public:
    Date(int d,int m,int y):day(d),month(m),year(y){}
    void DisplayDate()
    {
        cout<<"Today's date: "<<endl<<day<<"/"<<month<<"/"<<year;
    }
};
int main()
{
    int month,day,year;
    cout<<"Enter Day: ";
    cin>>day;
    cout<<"Enter Month: ";
    cin>>month;
    cout<<"Enter year: ";
    cin>>year;
    Date DateTest(day,month,year);
    DateTest.DisplayDate();
}
