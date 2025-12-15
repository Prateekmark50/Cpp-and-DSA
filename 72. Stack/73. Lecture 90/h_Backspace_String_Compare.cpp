// Leetcode:- Backspace String Compare
// Link:- https://leetcode.com/problems/backspace-string-compare/

/*
Example 1:

Input: s = "ab#c", t = "ad#c"
Output: true
Explanation: Both s and t become "ac".

Example 2:

Input: s = "ab##", t = "c#d#"
Output: true
Explanation: Both s and t become "".

Example 3:

Input: s = "a#c", t = "b"
Output: false
Explanation: s becomes "c" while t becomes "b".
*/ 

#include <iostream>
#include <stack>
using namespace std;

bool backspaceCompare(string s, string t) {
    stack<char> st1;
    stack<char> st2;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '#') {
            if (!st1.empty()) {
                st1.pop();
            }
        }
        else {
            st1.push(s[i]);
        }
    }
    for (int i = 0; i < t.size(); i++) {
        if (t[i] == '#') {
            if (!st2.empty()) {
                st2.pop();
            }
        }
        else {
            st2.push(t[i]);
        }
    }
    return st1 == st2;
}

int main() {
    string s,t;
    cout << "Enter the string 1: ";
    cin >> s;
    cout << "Enter the string 2: ";
    cin >> t;

    cout << "The Backspace string comparision: " << backspaceCompare(s, t) << endl;
}