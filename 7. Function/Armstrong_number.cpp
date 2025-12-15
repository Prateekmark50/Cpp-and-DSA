#include<iostream>
using namespace std;

int Count_Digit(int n)
{
    int count=0;
    while(n){
        count++;
        n/=10;
    }
    return count;
}

bool Armstrong(int num , int digit)
{
    int n=num, rem, ans=0;
    while(n){
        rem/=10;
        n/=10;
        ans=ans+pow(rem,digit);
    }
    if(ans==num)
    return 1;
    else
    return 0;
}

int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    //Count number
    int digit= Count_Digit(num);
    //Armstrong Number
    cout<<Armstrong(num,digit)<<endl;
}

//OR
/*
#include<iostream>
using namespace std;

int Count_Digit(int n)
{
    int count=0;
    while(n){
        count++;
        n/=10;
    }
    return count;
}

void Armstrong(int num , int digit)
{
    int n=num, rem, ans=0;
    while(n){
        rem/=10;
        n/=10;
        ans=ans+pow(rem,digit);
    }
    if(ans==num)
    cout<<1;
    else
    cout<<0;
}

int main(){
    int num;
    cout<<"Enter the number:";
    cin>>num;
    //Count number
    int digit= Count_Digit(num);
    //Armstrong Number
    Armstrong(num,digit)<<endl;
}
*/

