#include<iostream>
using namespace std;

bool checkPalindrome(string str, int start, int end){
    // Base Case
    if(start >= end){
        return 1;
    }
    // Not Matched
    if(str[start] != str[end]){
        return 0;
    }
    // Matched
    else{
        return checkPalindrome(str, start+1, end-1);
    }
}

int main(){
    // Check Palindrome
    string str = "naman";
    cout << checkPalindrome(str,0,4);
}