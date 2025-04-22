#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Logger {
    vector<string> logs;
    const size_t maxLogs = 1000;

    void storeLog(const string& msg) {
        if (logs.size() >= maxLogs)
            logs.erase(logs.begin());
        logs.push_back(msg);
    }

public:
    void log(string severity, string message) {
        storeLog(severity + ": " + message);
    }

    vector<string> retrieveLogs(bool authenticated) const {
        if (authenticated)
            return logs;
        return {};
    }
};

int main() {
    Logger logger;
    logger.log("INFO", "Network module initialized");
    logger.log("ERROR", "Database connection failed");

    vector<string> logs = logger.retrieveLogs(true);
    for (const auto& log : logs)
        cout << log << endl;
}