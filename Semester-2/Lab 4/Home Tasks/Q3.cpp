#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class Invoice
{
    string pnum;
    string pdesc;
    int quantity;
    double price;
    public:
    Invoice(string num,string desc,int quan,double cost):pnum(num),pdesc(desc),quantity(quan),price(cost){
        if(price<0)
        price=0;
        if(quantity<0)
        quantity=0;
    }
    double getInvoiceAmount()
    {
        return quantity*price;
    }
};
int main()
{
    string pnum,pdesc;
    int quan;
    double price;
    cout<<"Enter Product Number: ";
    getline(cin,pnum);
    cout<<"Enter Product Description: ";
    getline(cin,pdesc);
    cout<<"Enter the quantity available: ";
    cin>>quan;
    cout<<"Enter the price of the product: ";
    cin>>price;
    Invoice h1(pnum,pdesc,quan,price);
    cout<<"Invoice amount: "<<h1.getInvoiceAmount();

}
