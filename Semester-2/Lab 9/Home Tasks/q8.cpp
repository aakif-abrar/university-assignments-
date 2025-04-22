#include<iostream>
#include<string>
using namespace std;

class Student {
public:
    virtual float getTuition(string status, int credits) = 0;
};

class GraduateStudent : public Student {
    string researchTopic;
public:
    void setResearchTopic(string topic) {
        researchTopic = topic;
    }

    string getResearchTopic() {
        return researchTopic;
    }

    float getTuition(string status, int credits) {
        if (status == "undergraduate") return credits * 200;
        if (status == "graduate") return credits * 300;
        if (status == "doctoral") return credits * 400;
        return 0;
    }
};

int main() {
    GraduateStudent gs;
    gs.setResearchTopic("AI Research");
    cout << gs.getTuition("graduate", 12) << endl;
}