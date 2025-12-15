#include<iostream>
using namespace std;

int Power(int num, int n){
    // Base Case
    if(n == 0){
        return 1;
    }
    
    return num*Power(num, n-1);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << Power(2, n);
}