#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Account
{
    float bal;
    public:
    Account():bal(20000){}
    void credit(int amt)
    {
        bal+=amt;
        cout<<"Amount added succesfully!"<<endl;
    }
    void debit(int amt)
    {
        bal-=amt;
        if(bal<0)
        bal=0;
        cout<<"Amount withdrawn succesfully!"<<endl;
    }
    float getBalance()
    {
        return bal;
    }
};
int main()
{
    Account a1;
    int amt;
    cout<<"Enter amount to deposit: ";
    cin>>amt;
    a1.credit(amt);
    cout<<"Enter amount to withdraw: ";
    cin>>amt;
    a1.debit(amt);
    cout<<"Final Balance: "<<a1.getBalance();
}
