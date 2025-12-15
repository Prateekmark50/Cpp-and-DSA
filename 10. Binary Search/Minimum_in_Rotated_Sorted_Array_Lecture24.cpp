#include<iostream>
using namespace std;

int findMin(int arr[], int n){
    int start=0, end=n-1, mid, ans=arr[0];
    while(start<=end){
        mid = start+(end-start)/2;
        // Left side sorted array
        if(arr[mid]>=arr[0])
        start = mid+1;
        // Right side sorted
        else{
            ans=arr[mid];
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the element of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The minimum number in rotated sorted array is: "<<findMin(arr, n)<<endl;
}