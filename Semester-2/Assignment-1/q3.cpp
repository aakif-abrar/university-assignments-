#include<iostream>
#include<string>
using namespace std;
int main(){
	int id,units;
	float rate;
	string name;
	cout<<"Customer id: ";
	cin>>id;
	getchar();
	cout<<"Customer name: ";
	getline(cin,name);
	cout<<"Units consumed: ";
	cin>>units;
	if(units>=0 && units<200)
	rate=16.2;
	else if(units>=200 && units<300)
	rate=20.1;
	else if(units>=300 && units<500)
	rate=27.1;
	else if(units>=500)
	rate=35.9;
	else
	{
	cout<<"Invalid rates entered"<<endl<<"program ended...";
	return 0;
	}
	float amount=units*rate,surcharge=0;
	cout<<"Amount charges: @Rs. "<<rate<<" per unit: "<<amount<<endl;
	if(units*rate>18000)
	{
	surcharge=0.15*amount;
	cout<<"Surcharge amount: "<<surcharge<<endl;
	}
	cout<<"Net amount paid by the customer: "<<amount+surcharge;
}
