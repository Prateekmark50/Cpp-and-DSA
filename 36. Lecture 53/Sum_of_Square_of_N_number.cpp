#include<iostream>
using namespace std;

int SumSquare(int n){
    // Base Case
    if(n == 1){
        return 1;
    }
    
    return n*n + SumSquare(n-1);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << SumSquare(n);
}
