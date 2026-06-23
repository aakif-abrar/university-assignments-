#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

class User {
public:
    string userId;
    string firstName;
    string lastName;
    string address;
    string email;

    User() {}

    User(string id, string first, string last, string addr, string mail) {
        userId = id;
        firstName = first;
        lastName = last;
        address = addr;
        email = mail;
    }

    string ToString() {
        return userId + "," + firstName + "," + lastName + "," + address + "," + email;
    }
};

class Product {
public:
    string productId;
    string productName;
    string description;
    int price;

    Product() {}

    Product(string id, string name, string desc, int pr) {
        productId = id;
        productName = name;
        description = desc;
        price = pr;
    }

    string ToString() {
        return productId + "," + productName + "," + description + "," + to_string(price);
    }
};

class Order {
public:
    string orderId;
    string userId;
    string productId;
    int totalPaid;

    Order() {}

    Order(string oId, string uId, string pId, int paid) {
        orderId = oId;
        userId = uId;
        productId = pId;
        totalPaid = paid;
    }

    string ToString() {
        return orderId + "," + userId + "," + productId + "," + to_string(totalPaid);
    }
};

class DatabaseSystem {
private:
    vector<User> users;
    vector<Product> products;
    vector<Order> orders;

    void LoadUsers() {
        ifstream inFile("users.txt");
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id, first, last, addr, mail;
            getline(ss, id, ',');
            getline(ss, first, ',');
            getline(ss, last, ',');
            getline(ss, addr, ',');
            getline(ss, mail, ',');
            users.push_back(User(id, first, last, addr, mail));
        }
        inFile.close();
    }

    void LoadProducts() {
        ifstream inFile("products.txt");
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string id, name, desc, priceStr;
            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, desc, ',');
            getline(ss, priceStr, ',');
            products.push_back(Product(id, name, desc, stoi(priceStr)));
        }
        inFile.close();
    }

    void LoadOrders() {
        ifstream inFile("orders.txt");
        string line;
        while (getline(inFile, line)) {
            stringstream ss(line);
            string orderId, userId, productId, paidStr;
            getline(ss, orderId, ',');
            getline(ss, userId, ',');
            getline(ss, productId, ',');
            getline(ss, paidStr, ',');
            orders.push_back(Order(orderId, userId, productId, stoi(paidStr)));
        }
        inFile.close();
    }

public:
    void InsertDummyData() {
        ofstream userFile("users.txt");
        userFile << "U1,Linus,Torvalds,Finland,linus@email.com\n";
        userFile << "U2,Steve,Jobs,USA,steve@email.com\n";
        userFile.close();

        ofstream productFile("products.txt");
        productFile << "P1,Laptop,High-end gaming laptop,1500\n";
        productFile << "P2,Phone,Latest smartphone,800\n";
        productFile << "P3,Tablet,Lightweight tablet,400\n";
        productFile.close();

        ofstream orderFile("orders.txt");
        orderFile << "O1,U1,P1,1500\n";
        orderFile << "O2,U1,P3,400\n";
        orderFile << "O3,U2,P2,800\n";
        orderFile.close();
    }

    void FetchProductsByUser(string userName) {
        LoadUsers();
        LoadProducts();
        LoadOrders();

        string foundUserId = "";

        for (User user : users) {
            if (user.firstName == userName) {
                foundUserId = user.userId;
                break;
            }
        }

        if (foundUserId == "") {
            cout << "User not found!" << endl;
            return;
        }

        vector<string> productIdsOrdered;
        for (Order order : orders) {
            if (order.userId == foundUserId) {
                productIdsOrdered.push_back(order.productId);
            }
        }

        cout << "Products ordered by " << userName << ":" << endl;
        for (Product product : products) {
            for (string pId : productIdsOrdered) {
                if (product.productId == pId) {
                    cout << "- " << product.productName << endl;
                }
            }
        }
    }
};

int main() {
    DatabaseSystem db;

    db.InsertDummyData(); 
    db.FetchProductsByUser("Linus");

    return 0;
}
