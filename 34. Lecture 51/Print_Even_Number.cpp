#include<iostream>
using namespace std;

void print(int n){
    // Base Case
    if(n == 2) {
        cout << 2 << endl;
        return;
    }
    cout << n << endl;
    print(n-2);
}

int main(){
    int n = 10;
    // Printing Even number using Recursive Approach
    print(n);
}