#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main() 
{
    string name;
    int ctick, atick, ticks;
    float cprice, aprice, gross, charity;
    cout << "Name:";
    getline(cin, name);
    cout << "Number of child tickets: ";
    cin >> ctick;
    cout << "Number of adult tickets: ";
    cin >> atick;
    ticks = ctick + atick;
    cout << "Price of child ticket: ";
    cin >> cprice;
    cout << "Price of adult ticket: ";
    cin >> aprice;
    gross = ctick * cprice + atick * aprice;
    cout << "Percentage of Gross Amount Donated: ";
    cin >> charity;
    float net_sale = gross - (charity / 100) * gross;
    cout << setw(30) << left << setfill('-') << "Name: " << name << endl;
    cout << setw(30) << left << "Total Tickets Sold: " << ticks << endl;
    cout << setw(30) << left << "Gross Price: " << fixed << setprecision(2) << gross << endl;
    cout << setw(30) << left << "Percentage Donated: " << charity << "%" << endl;
    cout << setw(30) << left << "Amount Donated: " << (charity / 100) * gross << endl;
    cout << setw(30) << left << "Net Sale: " << net_sale << endl;
    return 0;
}
