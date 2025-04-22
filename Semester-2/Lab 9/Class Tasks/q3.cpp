#include<iostream>
#include<string>
using namespace std;

class PatientRecord {
    string name, id, dob, medicalHistory, billingInfo;

public:
    PatientRecord(string n, string i, string d)
        : name(n), id(i), dob(d) {}

    string getPublicData() const {
        return "Name: " + name + ", ID: " + id;
    }

    string getMedicalData() const {
        return medicalHistory;
    }

    void updateMedicalHistory(string history) {
        medicalHistory = history;
    }

    void addBillingDetails(string billing) {
        billingInfo = billing;
    }

    friend class Doctor;
    friend class Billing;
};

class Doctor {
public:
    void accessRecord(PatientRecord& record) {
        record.updateMedicalHistory("Flu, Cold");
    }
};

class Billing {
public:
    void bill(PatientRecord& record) {
        record.addBillingDetails("Paid $500");
    }
};

int main() {
    PatientRecord p("John", "P001", "01-01-1990");
    Doctor d;
    Billing b;
    d.accessRecord(p);
    b.bill(p);
    cout << p.getPublicData() << endl;
}