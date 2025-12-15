#include<iostream>
#include<vector>
using namespace std;

bool threeSum(vector<int>&arr, int n, int X){
    // // Method 1: Brute Force
    // for(int i=0; i<n-2; i++){
    //     for(int j=i+1; j<n-1; j++){
    //         for(int k=j+1; k<n; k++){
    //             if(arr[i]+arr[j]+arr[k]==X)
    //             return 1;
    //         }
    //     }
    // }
    // return 0;

    // // Method 2:
    // for(int i=0; i<n-2; i++){
    //     for(int j=i+1; j<n-1; j++){
    //         int ans = X - arr[i] - arr[j];
    //         int start = j+1, end = n-1;
    //         while(start<=end){
    //             int mid = start+(end-start)/2;
    //             if(arr[mid] == ans)
    //             return 1;
    //             else if(arr[mid] < ans)
    //             start = mid+1;
    //             else
    //             end = mid-1;
    //         } 
    //     }
    // }
    // return 0;

    // Method 3: Using Two Pointer
    for(int i = n-2; i>=0;i--){
        for(int j=0; j<=i; j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
    for(int i=0; i<n-2; i++){
        int ans = X - arr[i];
        int start = i + 1, end = n-1;
        while(start<=end){
            if(arr[start] + arr[end] == ans)
            return 1;
            else if(arr[start] + arr[end] < ans)
            start++;
            else
            end--;
        }
    }
    return 0;
}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the element of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    cout<<"The three sum for the given target is: "<<threeSum(arr, n, target);
}