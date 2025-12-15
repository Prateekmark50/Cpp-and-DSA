#include<iostream>
using namespace std;

int Factorial(int n){
    // Base Case
    if(n == 0 || n == 1){
        return 1;
    }
    return n * Factorial(n-1);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    if(n < 0){
        cout << "Factorial is not possible\n";
        return 0;
    }
    cout << "Factorial of " << n << " is: "<< Factorial(n);
}