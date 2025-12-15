#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findlps(vector<int> lps, string s) {
    int prefix = 0, suffix = 1;
    while (suffix < s.size()) {
        // Matched
        if (s[prefix] == s[suffix]) {
            lps[suffix] = prefix + 1;
            suffix++, prefix++;
        }
        // Not Matched
        else{
            if (prefix == 0) {
                lps[suffix] = 0;
                suffix++;
            }
            else{
                prefix = lps[prefix - 1];
            }
        }
    }
}

int KMP_MATCH(string haystack, string needle) {
    vector<int> lps(needle.size(), 0);
    findlps(lps, needle);
    int first = 0, second = 0;
    while (first < haystack.size() && second < needle.size()) {
        // Matched
        if (haystack[first] == needle[second]) {
            first ++, second++;
        }
        // Not Matched
        else{
            if (second == 0) {
                first++;
            }
            else{
                second = lps[second - 1];
            }
        }
    }
    // Answer Exist
    if (second == needle.size())
    return 1;

    return 0;
}

int repeatedStringMatch(string a, string b) {
    if (a == b)
    return 1;

    int repeat = 1;
    string temp = a;
    while (temp.size() < b.size()) {
        temp += a;
        repeat ++;
    }

    if (KMP_MATCH(temp, b) == 1)
    return repeat;

    if (KMP_MATCH(temp + a, b) == 1)
    return repeat + 1;

    return -1;
}

int main() {
    string a;
    string b;
    cout << "Enter the string a:";
    cin >> a;
    cout << "Enter the string b:";
    cin >> b;
    cout << repeatedStringMatch(a, b);
}