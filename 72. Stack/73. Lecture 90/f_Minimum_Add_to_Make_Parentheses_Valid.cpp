// Leetcode:- Minimum Add to Make Parentheses Valid
// Link:- https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

/*
Example 1:

Input: s = "())"
Output: 1

Example 2:

Input: s = "((("
Output: 3
*/ 

#include <iostream>
#include <stack>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;
    int count = 0;

    for (int i = 0; i < s.size(); i++) {
        // Opening
        if (s[i] == '(') {
            st.push(s[i]);
        }
        // Closing
        else {
            if (st.empty()) {
                count++;
            }
            else {
                st.pop();
            }
        }
    }
    return count + st.size();
}

int main() {
    string s;
    cout << "Enter the string of Parentheses: ";
    cin >> s;

    cout << "The minimum bracket add to make Parentheses valid: " << minAddToMakeValid(s) << endl;
}