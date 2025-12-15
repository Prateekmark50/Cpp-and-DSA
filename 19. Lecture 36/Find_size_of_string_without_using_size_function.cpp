#include<iostream>
using namespace std;

int main(){
    string s = "Prateek";
    // Printing size of string without using size function
    int size = 0;
    while (s[size] != '\0'){
        size++;
    }
    cout << size << endl; 
}