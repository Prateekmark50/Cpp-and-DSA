#include<iostream>
#include<vector>
using namespace std;
bool threeSum(vector<int>&arr, int n, int X){
    // Sort the array
    for(int i = n-2; i>=0;i--){
        for(int j=0; j<=i; j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
    for(int i=0; i<n-3; i++){
        for(int j = i+1; j<n-2; j++){
            int ans = X - arr[i] - arr[j];
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
    }
    return 0;
}

int main(){
    int n;
    vector<int> arr(n);
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the element of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int target;
    cout<<"Enter the target: ";
    cin>>target;
    cout<<"The four sum for the given target is: "<<threeSum(arr, n, target);
}