#include<iostream>
#include<vector>
using namespace std;

int lps(string s) {
    int n = s.size();
    int maxlenght = 0;
    for (int len = 1; len < n; len++) {
        bool match = true;
        for (int i = 0; i < len; i++) {
            if (s[i] != s[n - len + i]) {
                match = false;
                break;
            }
        }
        if (match) {
            maxlenght = len;
        }      
    }
    return maxlenght;
}

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    int result = lps(s);
    cout << "The lenght of the longest prefix which is also a suffix: " << result << endl;
    return 0;
}