#include<iostream>
using namespace std;

int Sum(int n){
    // Base Case
    if(n==1){
        return 1;
    }
    return n + Sum(n-1);
}

int main(){
    int n;
    cout << "Enter the number:";
    cin >> n;
    cout << "Sum of " << n << " natural number is: " << Sum(n);
}