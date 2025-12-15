#include<iostream>
#include<math.h>
using namespace std;

int SumCubes(int n, int power){
    // Base Case
    if(n == 1){
        return 1;
    }
    
    return pow(n,power) + SumCubes(n-1,power);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << SumCubes(n,3);
}