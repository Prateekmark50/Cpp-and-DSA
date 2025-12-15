#include<iostream>
using namespace std;

int peakIndexInMountain(int arr[], int n){
    int start=0, end=n-1, mid;
    while(start<=end){
        mid = end+(start-end)/2;
        // Peak Element
        if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1])
        return mid;
        // Right side move
        else if(arr[mid]>arr[mid-1])
        start=mid+1;
        // Left side move
        else  //arr[mid]<arr[mid-1]
        end=mid-1;
    }
    return -1;
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

    cout<<"The peak index in array is "<<peakIndexInMountain(arr, n)<<endl;
}