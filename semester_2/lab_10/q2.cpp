#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

class Employee {
public:
    int id;
    string name;
    string designation;
    int yearsOfService;

    Employee() {}

    Employee(int i, string n, string d, int y) {
        id = i;
        name = n;
        designation = d;
        yearsOfService = y;
    }

    string ToString() {
        return to_string(id) + "," + name + "," + designation + "," + to_string(yearsOfService);
    }

    void Display() {
        cout << "ID: " << id << ", Name: " << name << ", Designation: " << designation << ", Years of Service: " << yearsOfService << endl;
    }
};

class EmployeeManager {
private:
    vector<Employee> employeeList;
    string fileName;

public:
    EmployeeManager(string file) {
        fileName = file;
    }

    void LoadData() {
        ifstream inFile(fileName);
        if (inFile.is_open()) {
            string line;
            while (getline(inFile, line)) {
                stringstream ss(line);
                string idStr, name, designation, yearsStr;
                getline(ss, idStr, ',');
                getline(ss, name, ',');
                getline(ss, designation, ',');
                getline(ss, yearsStr, ',');

                Employee emp(stoi(idStr), name, designation, stoi(yearsStr));
                employeeList.push_back(emp);
            }
            inFile.close();
        } else {
            cout << "Unable to open file for reading!" << endl;
        }
    }

    void SaveData() {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            for (Employee emp : employeeList) {
                outFile << emp.ToString() << endl;
            }
            outFile.close();
        } else {
            cout << "Unable to open file for writing!" << endl;
        }
    }

    vector<Employee> FindManagers() {
        vector<Employee> managers;
        for (Employee emp : employeeList) {
            if (emp.designation == "Manager" && emp.yearsOfService >= 2) {
                managers.push_back(emp);
            }
        }
        return managers;
    }

    void DeleteNonManagers() {
        vector<Employee> managers = FindManagers();
        employeeList = managers;
    }

    void IncrementData() {
        for (int i = 0; i < employeeList.size(); i++) {
            employeeList[i].id += 100; 
            employeeList[i].yearsOfService += 1; 
        }
    }

    void DisplayData() {
        for (Employee emp : employeeList) {
            emp.Display();
        }
    }

    void InsertDummyData() {
        ofstream outFile(fileName);
        if (outFile.is_open()) {
            outFile << "1,Ali,Manager,3" << endl;
            outFile << "2,Ahmed,Assistant,1" << endl;
            outFile << "3,Sara,Manager,5" << endl;
            outFile << "4,John,Clerk,2" << endl;
            outFile.close();
        } else {
            cout << "Unable to open file for writing dummy data!" << endl;
        }
    }
};

int main() {
    EmployeeManager manager("employeeData.txt");

    manager.InsertDummyData();
    manager.LoadData();

    cout << "\nAll Employees:" << endl;
    manager.DisplayData();

    cout << "\nManagers with at least 2 years:" << endl;
    vector<Employee> managers = manager.FindManagers();
    for (Employee emp : managers) {
        emp.Display();
    }

    cout << "\nDeleting non-manager records..." << endl;
    manager.DeleteNonManagers();
    manager.SaveData();

    cout << "\nIncrementing IDs and Years of Service..." << endl;
    manager.IncrementData();
    manager.SaveData();

    cout << "\nFinal Data:" << endl;
    manager.DisplayData();

    return 0;
}
