/*We have to print the Square root of given number in integer*/ 
#include<iostream>
using namespace std;
int main(){
    int num,i,ans;
    cout<<"Enter the number:";
    cin>>num;
    for(i=1;i<=num;i++){
        ans=i*i;
        if(num<=ans){
            cout<<i-1<<" ";
            break;
        }
    }
}