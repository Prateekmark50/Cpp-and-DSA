#include<iostream>
#include<vector>
using namespace std;

int maxDiff(vector<int>&arr , int n){
    int ans = INT32_MIN;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j]-arr[i]>ans){
                ans = arr[j]-arr[i];
            }
        }
    }
    return ans;
}

int main(){
    int n;
    vector<int> arr(n);
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the element of array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"The maximum difference between 2 element is: "<<maxDiff(arr, n);
}