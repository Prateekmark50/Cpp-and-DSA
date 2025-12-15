#include<iostream>
using namespace std;
int main(){
    int n,i,last=0,pre=1,curr;

    cout<<"Enter the number of terms:";
    cin>>n;

    cout<<"Fibonacci series up to "<<n<<" terms:"<<endl;

    for(i=0;i<n;i=i+1)
    {
        cout<<last<<endl;
        curr=last+pre;
        last=pre;
        pre=curr;
    }
    return 0;
}