#include<iostream>
using namespace std;

int gcd(int a, int b){
    // Base Case
    if(b == 0){
        return a;
    }
    
    return gcd(b,a%b);
}

int main(){
    int a,b;
    cout << "Enter the two number: ";
    cin >> a >> b;
    cout << gcd(a,b);
}
/*EXAMPLE:-
We have to find GCD of 18 and 48
GCD(18,48)
GCD(48,18%48)-->GCD(48,18)
GCD(18,48%18)-->GCD(18,12)
GCD(12,18%12)-->GCD(12,6)
GCD(6,12%6)-->GCD(6,0)  So 6 is the answer
*/