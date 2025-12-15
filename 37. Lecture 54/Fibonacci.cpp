#include<iostream>
using namespace std;

int Fibonacci(int n){
    // Base Case
    if(n <= 1){
        return n;
    }
    
    return Fibonacci(n-1) + Fibonacci(n-2);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << Fibonacci(n);
}