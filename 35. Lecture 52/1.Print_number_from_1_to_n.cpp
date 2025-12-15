#include<iostream>
using namespace std;

void print(int num, int N){
    // Base case
    if(num == N){
        cout << num << endl;
        return;
    }
    cout << num << endl;
    print(num+1, N);
}

void print1(int N){
    // Base Case
    if(N == 1){
        cout << 1 << endl;
        return;
    }
    print1(N-1);
    cout << N << endl;

}

int main(){
    // Print number from 1 to n using Double Arguments
    int N;
    cout << "Enter the number: ";
    cin >> N;
    print(1,N); 

    // Print number from 1 to n using Single Arguments
    print1(N);
}