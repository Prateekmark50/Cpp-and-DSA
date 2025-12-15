#include<iostream>
using namespace std;

int searchInsert(int arr[], int n, int target){
    int start=0, end=n-1, mid, ans =n;
    while(start<=end){
        mid = start+(end-start)/2;
        if(arr[mid]==target){
            ans = mid;
            break;
        }
        else if(arr[mid]<target)
        start = mid+1;
        else{
            ans=mid;
            end = mid-1;
        }
    }
    return ans;
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

    cout<<"The index where "<<target<<" wouls be if it was inserted in order: "<<searchInsert(arr,n,target)<<endl;
    return 0;
}