#include <iostream>
#include <vector>
using namespace std;

class CoffeeShop {
    string name;
    vector<pair<string, double>> menu;
    vector<string> orders;
public:
    CoffeeShop(string n, vector<pair<string, double>> m) : name(n), menu(m) {}
    string addOrder(string item) { for (auto& m : menu) if (m.first == item) { orders.push_back(item); return ""; } return "This item is currently unavailable!"; }
    string fulfillOrder() { if (!orders.empty()) { string item = orders.front(); orders.erase(orders.begin()); return "The " + item + " is ready!"; } return "All orders have been fulfilled"; }
};

int main() {
    CoffeeShop shop("Cafe", {{"Latte", 5.0}, {"Muffin", 3.0}});
    cout << shop.addOrder("Latte") << endl;
    cout << shop.fulfillOrder() << endl;
    return 0;
}