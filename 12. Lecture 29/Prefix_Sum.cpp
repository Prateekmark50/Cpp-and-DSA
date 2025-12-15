#include<iostream>
#include<vector>
using namespace std;

void prefixSum(vector<int> arr , int n){

    vector<int> prefix(n);
    prefix[0]=arr[0];

    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+arr[i];
    }
    cout<<"The Prefix Sum array of given array is: ";
    for(int i = 0; i < n; i++){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the element of array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    prefixSum(arr, n);
}