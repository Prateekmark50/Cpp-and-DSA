#include<iostream>
using namespace std;

void Swap(int &m , int &n)        // Pass by Reference
{        
    int c = m;
    m=n;
    n=c;
}

void Swap(float &c , float &d)        // Pass by Reference
{        
    float r = c;
    c=d;
    d=r;
}

 int main(){
    int a,b;
    cout<<"Enter 2 number:";
    cin>>a>>b;

    Swap(a,b);
    cout<<a<<" "<<b<<endl;

    float f1=8.2, f2=5.3;
    Swap(f1,f2);
    cout<<f1<<" "<<f2<<endl;
 }