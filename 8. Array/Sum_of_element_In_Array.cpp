#include<iostream>
using namespace std;

int main(){
    int ans=0;
    int arr[]={5,83,4,5,9};
    for(int i=0;i<5;i++){
        ans=ans+arr[i];
    }
    cout<<ans;
}