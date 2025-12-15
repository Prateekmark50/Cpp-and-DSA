#include<iostream>
using namespace std;
/*NOTE:-
We will solve this dynamic programming as this is right but it is showing Time Limit Exceeded using Recursion
*/
int climbStairs(int n){
    // Base Case
    if(n <= 1){
        return 1;
    }
    
    return climbStairs(n-1) + climbStairs(n-2);
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << climbStairs(n);
}