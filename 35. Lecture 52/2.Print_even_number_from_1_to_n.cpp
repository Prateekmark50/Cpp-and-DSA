#include<iostream>
using namespace std;

void printeven(int num, int N){
    // Base Case
    if(num == N){
        cout << num << endl; 
        return;
    }
    cout << num << endl;
    printeven(num+2, N);
}

void printeven1(int N){
    // Base Case
    if(N == 2) {
        cout << 2 << endl;
        return;
    }
    printeven1(N-2);
    cout << N << endl;
}

int main(){
    // Print even number from 1 to n using Double Arguments
    int N;
    cout << "Enter the number: ";
    cin >> N;
    if(N%2==1){
        N--;
    }
    printeven(2, N); 

    // Print even number from 1 to n using Single Arguments
    printeven1(N);
}