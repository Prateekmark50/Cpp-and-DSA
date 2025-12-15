// GFG:- Print Bracket Number
// Link:- https://www.geeksforgeeks.org/problems/print-bracket-number4058/1

/*
Examples:

Input:  str = "(aa(bdc))p(dee)"
Output: 1 2 2 1 3 3
Explanation: The highlighted brackets in
the given string (aa(bdc))p(dee) are
assigned the numbers as: 1 2 2 1 3 3.

Input:  str = "(((()("
Output: 1 2 3 4 4 5
Explanation: The highlighted brackets in
the given string (((()( are assigned
the numbers as: 1 2 3 4 4 5
*/ 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> bracketNumbers(string str) {
    int count = 0;
    stack<int> st;
    vector<int> ans;

    for (int i = 0; i < str.size(); i++) {
        // Opening Bracket
        if (str[i] == '(') {
            count++;
            st.push(count);
            ans.push_back(count);
        }
        // Closing Bracket
        else if (str[i] == ')') {
            ans.push_back(st.top());
            st.pop();
        }
    }
    
    return ans;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    vector<int> result = bracketNumbers(str);

    cout << "Print Bracket Number: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}