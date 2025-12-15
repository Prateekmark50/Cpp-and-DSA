#include<iostream>
using namespace std;

void print(int n){
    // Base Case
    if(n == 1) {
        cout << 1 << endl;
        return;
    }
    cout << n << endl;
    print(n-1);
}

int main(){
    int n = 5;
    // Print n to 1 using Iterative Approach
    for(int i = n; i > 0; i--){
        cout << i << endl;
    }

    // Print n to 1 using Recursive Approach
    print(n);
}