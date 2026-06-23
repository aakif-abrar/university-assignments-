#include <iostream>
#include <fstream>
#include <sstream>
#include <string> 
#include <vector>  
#include <cstdio>  
using namespace std;


class Task {
public:
    string taskName;
    bool isDone;

    Task() {}

    Task(string name, bool done = false) {
        taskName = name;
        isDone = done;
    }

    string ToString() {
        return taskName + "," + (isDone ? "1" : "0");
    }
};

class ToDoListManager {
private:
    const string fileName = "tasks.txt";
    vector<Task> tasks;

    void LoadTasks() {
        tasks.clear();
        ifstream inFile(fileName);
        string line;
        while (getline(inFile, line)) {
            size_t pos = line.find(',');
            string name = line.substr(0, pos);
            bool done = (line.substr(pos + 1) == "1");
            tasks.push_back(Task(name, done));
        }
        inFile.close();
    }

    void SaveTasks() {
        ofstream outFile(fileName, ios::trunc);
        for (Task t : tasks) {
            outFile << t.ToString() << endl;
        }
        outFile.close();
    }

public:
    void AddTask(string taskName) {
        LoadTasks();
        tasks.push_back(Task(taskName, false));
        SaveTasks();
        cout << "Task Added!" << endl;
    }

    void ViewTasks() {
        LoadTasks();
        cout << "To-Do List:" << endl;
        int index = 1;
        for (Task t : tasks) {
            cout << index++ << ". " << t.taskName << (t.isDone ? " [Done]" : "") << endl;
        }
    }

    void MarkTaskDone(int taskNumber) {
        LoadTasks();
        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].isDone = true;
            SaveTasks();
            cout << "Task marked as done!" << endl;
        } else {
            cout << "Invalid task number!" << endl;
        }
    }
};

int main() {
    ToDoListManager manager;
    int choice;
    string taskName;
    int taskNum;

    do {
        cout << "\n===== To-Do List Manager =====" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Done" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Enter task name: ";
            getline(cin, taskName);
            manager.AddTask(taskName);
            break;
        case 2:
            manager.ViewTasks();
            break;
        case 3:
            cout << "Enter task number to mark done: ";
            cin >> taskNum;
            manager.MarkTaskDone(taskNum);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid Choice!" << endl;
        }
    } while (choice != 4);

    return 0;
}
