#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Method 1
bool ispalindrome(string str) {
    int n = str.size();
    int start = 0, end = n - 1; 
    while (start < end) {
        if (str[start] != str[end]) {
            return 0;
        }
        start++, end--;
    }
    return 1;
}
int minChar1(string str) {
    int count = 0;
    while (str.size() > 0 && ispalindrome(str) == 0) {
        str.pop_back();
        count++;
    }
    return count;
}

// Method 2
int minChar2(string str) {
    // String ko reverse kardo
    string rev = str;
    reverse (rev.begin(), rev.end());
    int size = str.size();
    str += '$'; // Separator
    str += rev; // Reverse

    // Longest prefix nikalna hai
    int n = str.size();
    vector<int> lps(n,0);

    int prefix = 0, suffix = 1;

    while (suffix < str.size()) {
        // Matched
        if (str[prefix] == str[suffix]) {
            lps[suffix] = prefix + 1;
            prefix ++, suffix ++;
        }
        // Not Matched
        else {
            if (prefix == 0) {
                lps[suffix] = 0;
                suffix ++;
            }
            else {
                prefix = lps[prefix + 1];
            }
        }
    }
    return size - lps[n - 1];
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    cout << "Output of method 1" << endl;
    cout << "The no. of character to be added in starting of string: " << minChar1(str) << endl;
    cout << "Output of method 2" << endl;
    cout << "The no. of character to be added in starting of string: " << minChar2(str) << endl;
}