#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdio>
using namespace std;

class Logger {
private:
    const string baseFileName = "log";
    const int maxFileSize = 1024 * 1024; 
    int logFileIndex = 1;
    string currentFileName;

    void RotateLog() {
        stringstream ss;
        ss << baseFileName << logFileIndex << ".txt";
        string newFileName = ss.str();
        if (rename(currentFileName.c_str(), newFileName.c_str()) != 0) {
            cout << "Error rotating log file!" << endl;
        } else {
            logFileIndex++;
        }
    }

    long GetFileSize(const string& fileName) {
        ifstream inFile(fileName, ios::binary | ios::ate);
        return inFile.tellg();
    }

public:
    Logger() {
        currentFileName = "currentLog.txt";
        ofstream outFile(currentFileName, ios::app); 
        outFile.close();
    }

    void WriteLog(string message) {
        if (GetFileSize(currentFileName) >= maxFileSize) {
            RotateLog();
            ofstream clearFile(currentFileName, ios::trunc);
            clearFile.close();
        }

        ofstream outFile(currentFileName, ios::app);
        outFile << message << endl;
        outFile.close();
    }
};

int main() {
    Logger logger;

    for (int i = 1; i <= 10000; i++) {
        logger.WriteLog("Log entry number: " + to_string(i));
    }

    cout << "Logging complete." << endl;
    return 0;
}
