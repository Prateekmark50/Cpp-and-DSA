#include<iostream>
using namespace std;

void Sum(int m , int n){      //Function declare
    int ans =m+n;             //Function define
    cout<<ans<<endl;
}

int Mul(int m , int n){
    int ans= m*n;
    return ans;
}

int main(){
    int a,b;
    cout<<"Enter 2 number:";
    cin>>a>>b;
    cout<<"The sum of two number is:";
    Sum(a,b);

    cout<<"The multiply of two number is:"<<Mul(a,b)<<endl;
}