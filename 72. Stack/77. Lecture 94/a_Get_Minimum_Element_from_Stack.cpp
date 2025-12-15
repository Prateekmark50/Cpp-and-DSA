// GFG:- Get Minimum Element from Stack
// Link:- https://www.geeksforgeeks.org/problems/get-minimum-element-from-stack/1

/*
Examples:

Input: q = 7, queries[][] = [[1, 2], [1, 3], [3], [2], [4], [1, 1], [4]]
Output: [3, 2, 1]
Explanation: 
push(2): Stack is [2]
push(3): Stack is [2, 3]
peek(): Top element is 3
pop(): Removes 3, stack is [2]
getMin(): Minimum element is 2
push(1): Stack is [2, 1]
getMin(): Minimum element is 1

Input: q = 4, queries[][] = [[1, 4], [1, 2], [4], [3], [5]]
Output: [2, 2, false]
Explanation: 
push(4): Stack is [4]
push(2): Stack is [4, 2]
getMin(): Minimum element is 2
peek(): Top element is 2
isEmpty(): false
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void push(int x) {}

void pop() {}

int peek() {}

bool isEmpty() {}

int getMin() {}

int main() {
    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    vector<vector<int>> queries(q);
    cout << "Enter queries (example: 1 5 or 4):\n";

    // Taking input for all queries
    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            queries[i] = {type, x};
        } else {
            queries[i] = {type};
        }
    }

    vector<string> output;

    for (auto &query : queries) {
        int type = query[0];
        if (type == 1) {
            push(query[1]);
        } 
        else if (type == 2) {
            pop();
        } 
        else if (type == 3) {
            output.push_back(to_string(peek()));
        } 
        else if (type == 4) {
            output.push_back(to_string(getMin()));
        } 
        else if (type == 5) {
            output.push_back(isEmpty() ? "true" : "false");
        }
    }

    cout << "\nOutput: [";
    for (int i = 0; i < output.size(); i++) {
        cout << output[i];
        if (i != output.size() - 1) cout << ", ";
    }
    cout << "]\n";

    return 0;
}