// GFG:-Stream First Non-repeating
// Link:- https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1

/*
Examples:

Input: s = "aabc"
Output: a#bb
Explanation: 
At i=0 ("a"): First non-repeating character is 'a'.
At i=1 ("aa"): No non-repeating character, so '#'.
At i=2 ("aab"): First non-repeating character is 'b'.
At i=3 ("aabc"): Non-repeating characters are 'b' and 'c'; 'b' appeared first, so 'b'. 

Input: s = "bb" 
Output: "b#" 
Explanation: 
At i=0 ("b"): First non-repeating character is 'b'.
At i=1 ("bb"): No non-repeating character, so '#'.
*/ 

#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

string firstNonRepeating(string &s) {
    string B = "";
    queue<char> q;
    vector<int> repeated(26, 0);
    
    for (int i = 0; i < s.size(); i++) {
        // if repeated
        if (repeated[s[i] - 'a'] >= 1) {
            repeated[s[i] - 'a']++;
            while (!q.empty() && repeated[q.front() - 'a'] > 1) {
                q.pop();
            }
            
            if (q.empty()) {
                B += '#';
            } 
            else {
                B += q.front();
            }
        }
        // Non-repeated
        else {
            repeated[s[i] - 'a']++;
            q.push(s[i]);
            
            while (!q.empty() && repeated[q.front() - 'a'] > 1) {
                q.pop();
            }
            
            B += q.front();
        }
    }
    return B;
}

int main() {
    string s;
    cout << "Enter the string (only lowercase letters): ";
    cin >> s;

    string result = firstNonRepeating(s);

    cout << "\nFirst non-repeating characters in stream:\n";
    cout << result << endl;

    return 0;
}
