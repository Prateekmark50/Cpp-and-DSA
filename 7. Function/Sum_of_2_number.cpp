#include<iostream>
using namespace std;

int Sum(int m , int n){      //Function declare
    int ans =m+n;            //Function define
    return ans;
}

int Mul(int m , int n){
    int ans= m*n;
    return ans;
}

void fun(){
    cout<<"Hello World\n";
}

int main(){
    int a,b;
    cout<<"Enter 2 number:";
    cin>>a>>b;

    //Function call
    cout<<"The sum of two number is:"<<Sum(a,b);
    cout<<endl;
    
    cout<<"The multiply of two number is:"<<Mul(a,b)<<endl;

    fun();
}

// OR
/*
#include<iostream>
using namespace std;

void Sum(int m , int n){
    int ans = m+n;
    cout<<ans<<endl;
}

int main(){
    int a,b;
    cout<<"Enter 2 number:";
    cin>>a>>b;

    Sum(a,b);
}
*/