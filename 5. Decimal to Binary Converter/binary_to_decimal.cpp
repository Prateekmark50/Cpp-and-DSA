#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    int rem,ans=0,mul=1;
    while(num>0){
        //remainder
        rem=num%10;
        //number ko divide kar do
        num=num/10;
        //ans
        ans=rem*mul+ans;
        //mul
        mul=mul*2;
    }
    cout<<ans<<endl;
}