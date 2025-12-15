// GFG
#include<iostream>
#include<cmath>
using namespace std;

void towerOfHanoi(int N, int source, int help, int destination){
    if(N == 1){
        cout << "move the disk " << N << " from rod " << source << " to rod " << destination << endl;
        return;
    }
    towerOfHanoi(N-1, source, destination, help);
    cout << "move the disk " << N << " from rod " << source << " to rod " << destination << endl;
    towerOfHanoi(N-1, help, source, destination);
}

int main(){
    int N = 3;
    int source = 1;
    int help = 2;
    int destination = 3;
    towerOfHanoi(N, source, help, destination);
    cout << pow(2,N)-1;
}