#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <sstream>

using namespace std;
int findLoopStart(const vector<string>& commands, size_t ci) {
    int nestedLoops = 0;
    for (size_t i = ci - 1; i != size_t(-1); --i) { 
        if (commands[i] == "done") {
            nestedLoops++;
        } else if (commands[i] == "do") {
            if (nestedLoops == 0) {
                return i;
            }
            nestedLoops--;
        }
    }
    return 0;
}


int findLoopEnd(const vector<string>& commands, size_t ci) {
    int nestedLoops = 0;
    for (size_t i = ci + 1; i < commands.size(); ++i) {
        if (commands[i] == "do") {
            nestedLoops++;
        } else if (commands[i] == "done") {
            if (nestedLoops == 0) {
                return i;
            }
            nestedLoops--;
        }
    }
    return commands.size();
}

void processCommands(const vector<string>& commands) {
    stack<int> loopCounts;
    stack<int> currIter;
    string output = "";
    size_t index = 0;
    while (index < commands.size()) {
        string command = commands[index];

        if (command.find("for") == 0) {
            stringstream ss(command);
            string temp;
            int times;
            ss >> temp >> times;  
            loopCounts.push(times); 
            currIter.push(0); 
        } 
        else if (command == "do") {
        } 
        else if (command == "done") {
            int current = currIter.top() + 1;
            int max = loopCounts.top();
            currIter.pop();
            loopCounts.pop();

            if (current < max) {
                loopCounts.push(max);
                currIter.push(current);
                index = findLoopStart(commands, index);
                continue; 
            }
        } 
        else if (command.find("break") == 0) {
            stringstream ss(command);
            string temp;
            int breakAt;
            ss >> temp >> breakAt;
            if (currIter.top() + 1 == breakAt) {
                loopCounts.pop();
                currIter.pop();
                index = findLoopEnd(commands, index); 
            }
        } 
        else if (command.find("continue") == 0) {
            stringstream ss(command);
            string temp;
            int continueAt;
            ss >> temp >> continueAt;
            if (currIter.top() + 1 == continueAt) {
                int max = loopCounts.top();
                int current = currIter.top() + 1;
                currIter.pop();
                if (current < max) {
                    currIter.push(current);
                    index = findLoopStart(commands, index); 
                }
                continue; 
            }
        } 
        else if (command.find("print") == 0) {
            size_t start = command.find("\"") + 1;
            size_t end = command.rfind("\"");
            string message = command.substr(start, end - start);
            output += message + "\n";
        }

        ++index;
    }

    cout << output;
}

int main() {
    int n;
    cin >> n;
    cin.ignore(); 
    vector<string> commands(n);
    for (int i = 0; i < n; ++i) {
        getline(cin, commands[i]);
    }

    processCommands(commands);

    return 0;
}