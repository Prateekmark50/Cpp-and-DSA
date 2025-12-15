// Leetcode:- Valid Parentheses
// Link:- https://leetcode.com/problems/valid-parentheses/

/*
Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([])"
Output: true

Example 5:

Input: s = "([)]"
Output: false
*/ 

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (int i = 0; i < s.size(); i++) {
        // Opening
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        }
        // Closing
        else {
            // empty hai ya nahi
            if (st.empty()) {
                return false;
            }
            // )
            else if (s[i] == ')') {
                if (st.top() != '(') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
            // ]
            else if (s[i] == ']') {
                if (st.top() != '[') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
            // }
            else {
                if (st.top() != '{') {
                    return false;
                }
                else {
                    st.pop();
                }
            }
        }
    }
    return st.empty();
}

int main() {
    string s;
    cout << "Enter the string of Parentheses: ";
    cin >> s;

    cout << "The Parentheses valid(1) or not(0): " << isValid(s) << endl;
}