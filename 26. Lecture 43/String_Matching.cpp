#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Method 1:
int strStr1(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i <= n - m; i++) {
        int first = i, second = 0;
        while (second < m) {
            if (haystack[first] != needle[second]) {
                break;
            }
            else{
                first++, second++;
            }
        }
        if (second == m) {
            return first - second;
        }
    }
    return -1;
}

// Method 2:
void findlps(vector<int> &lps, string s) {
    int prefix = 0, suffix = 1;
    while (suffix < s.size()) {
        // Matched
        if (s[prefix] == s[suffix]) {
            lps[suffix] = prefix + 1;
            suffix ++, prefix ++;
        }
        // Not Matched
        else{
            if (prefix == 0) {
                lps[suffix] = 0;
                suffix ++;
            }
            else{
                prefix = lps[prefix - 1];
            }
        }
    }
}
int strStr2(string haystack, string needle) {
    vector<int> lps(needle.size(), 0);
    findlps(lps, needle);
    int first = 0, second = 0;
    while (first < haystack.size() && second < needle.size()) {
        // Matched
        if (haystack[first] == needle[second]) {
            first++, second++;
        }
        // Not Matched
        else{
            if (second == 0){
                first++;
            }
            else{
                second = lps[second - 1];
            }
        }
    }
    // Answer exist
    if (second == needle.size())
    return first - second;
    else
    return -1;

}

int main() {
    string haystack;
    string needle;
    cout << "Enter the string haystack: ";
    cin >> haystack;
    cout << "Enter the string needle: ";
    cin >> needle;
    cout << "The output of Method 1:" << endl;
    cout << strStr1(haystack, needle) << endl;
    cout << "The output of Method 2:" << endl;
    cout << strStr2(haystack, needle) << endl;
}