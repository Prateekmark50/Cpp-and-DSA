#include<iostream>
using namespace std;

int search(int arr[], int n, int target){
    int start=0, end=n-1, mid;
    while(start<=end){
        mid = start+(end-start)/2;
        // I found my element
        if(arr[mid]==target)
        return mid;
        // left side sorted
        else if(arr[mid]>arr[0]){
            if(arr[start]<=target && arr[mid]>=target)
            end = mid-1;
            else
            start = mid+1;
        }
        // Right side sorted
        else{
            if(arr[mid]<=target && arr[end]>=target)
            start = mid+1;
            else
            end = mid-1;
        }
    }
    return -1;
}

int main(){
    int arr[1000];
    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the element of array:";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target:";
    cin>>target;

    cout<<search(arr,n,target);
    return 0;
}