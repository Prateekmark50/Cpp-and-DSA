/*
Given an integer num, repeatedly add all its digits until the result has only one digit, and return it.
Example 1:
    Input: num=38
    Output: 2
    Explanation: The process is
    38 --> 3+8 --> 11
    11 --> 1+1 --> 2
    Since 2 has only one digit, return it.
    */
#include<iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    int rem,ans=0;
    while(num!=0){
        rem=num%10;
        num/=10;
        if(ans>INT32_MAX/10||ans<INT32_MIN/10){
            cout<<"Not valid";  
            return 0; 
        }
        ans=ans*10+rem;
    }
    cout<<ans<<endl;
}