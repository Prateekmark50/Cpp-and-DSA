// Leetcode :- Reverse String
// Link:- https://leetcode.com/problems/reverse-string/

/*
Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/ 
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void reverseString(vector<char>& s) {
    stack<int> st;
    for (int i = 0; i < s.size(); i++) {
        st.push(s[i]);
    }
    int i = 0;
    while (!st.empty()) {
        s[i] = st.top();
        i++;
        st.pop();
    }
}

int main() {
    string n;
    cout << "Enter the string: ";
    cin >> n; 

    vector<char> s(n.begin(), n.end());

    reverseString(s);

    for(char i = 0; i < s.size(); i++) {
        cout << s[i];
    }
}
/*
Time Complexity:
    O(N)
Space Complexity:
    O(N)
*/