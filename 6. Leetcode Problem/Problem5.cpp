#include<iostream>
using namespace std;
int main(){
    int x;
    cout<<"Enter the number:";
    cin>>x;
    if(x<0){
        return 0;
    }
    int num=x,rem,ans=0;
    while(num){
        rem=num%10;
        num=num/10;
        if(ans>INT32_MAX/10){
            return 0;
        }
        ans=ans*10+rem;
    }
    if(ans==x)
    cout<<"It is palindrome";
    else
    cout<<"It is not a palindrome";
}