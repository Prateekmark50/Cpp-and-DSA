#include<iostream>
using namespace std;

void reverseString(string &str, int start, int end){
    if(start >= end){
        return;
    }
    char c = str[start];
    str[start] = str[end];
    str[end] = c;
    reverseString(str, start+1, end-1);
}

int main(){
    // Reverse String
    string str = "rohit";
    reverseString(str,0,4);
    cout << str << endl;
}