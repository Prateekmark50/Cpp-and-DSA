#include<iostream>
using namespace std;

int main(){
    // char arr[] = {'a','p','p','l','e'};
    // cout << arr << endl;
    // for (int i = 0; i < 5; i++) {
    //     cout << arr[i];
    // }

    // char arr[10];
    // cin >> arr;
    // arr[2]  = '\0';
    // cout << arr;

    // // Given input and generate output
    // string s = "Rohit";
    // cout << s;

    // // Taking input from user to generate output
    // string s;
    // cin >> s;
    // cout << s;

    // // to printing string with space 
    // string s;
    // getline(cin, s);
    // cout << s << endl;
    // cout << s.size();

    // // To add two or more string
    // string s1 = "rohit", s2 = "mohit";
    // string s3 = s1 + s2;  // This method is to add two string
    // string s4 = s1.append(s2);  // This another method to add two string using append
    // cout << s3 << endl;
    // cout << s4 << endl;

    // // Use of push_back and pop_back in string
    // string s1 = "rohit";
    // s1.push_back('p');
    // cout << s1 << endl;
    // s1.pop_back();
    // cout << s1 << endl;
    // s1 = s1 + "p";
    // cout << s1 << endl;
    // s1 = s1 + 'p';
    // cout << s1;

    // How to use " " in string
    string s = "prateek is a \"good\" boy"; // Backslash is used which is called escape to print " " 
    cout << s << endl;
    string s1 = "\\0"; // To print \0 I have used escape(\) or backslash
    cout << s1 << endl;
}