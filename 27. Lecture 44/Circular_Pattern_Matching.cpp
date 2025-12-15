#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void findlps( vector<int> &lps, string needle) {
    int prefix = 0, suffix = 1;
    while (suffix < needle.size()) {
        // Matched
        if (needle[prefix] == needle[suffix]) {
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

bool circularPatternMatching(string haystack, string needle) {
    vector<int> lps(needle.size(), 0);
    findlps(lps, needle);
    haystack += haystack;
    int n = haystack.size();
    int first = 0, second = 0;
    while (first < haystack.size() && second < needle.size()) {
        // Matched
        if (haystack[first] == needle[second]) {
            first++, second++;
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
    // Answer exist
    if (second == needle.size())
    return 1;

    return 0;
}

int main() {
    string haystack;
    string needle;
    cout << "Enter the string haystack:";
    cin >> haystack;
    cout << "Enter the string needle:";
    cin >> needle;
    cout << "Do s2 string present in s1 or not: " << circularPatternMatching(haystack, needle);
}