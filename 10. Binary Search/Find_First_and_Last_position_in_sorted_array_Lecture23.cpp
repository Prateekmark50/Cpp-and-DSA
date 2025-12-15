#include<iostream>
using namespace std;

int firstOcc(int arr[], int n, int target){
    int start=0, end=n-1, mid, first=-1;
    // Find First
    while(start<=end)
    {
        // mid find karo
        mid=(start+end)/2;
        // arr[mid]==key
        if(arr[mid]==target){
            first=mid;
            end = mid-1;
        }
        // arrr[mid]<key
        else if(arr[mid]<target){
            start=mid+1;
        }
        // arrr[mid]>key
        else{
            end=mid-1;
        }
    }
    return first;
}

int lastOcc(int arr[], int n, int target){
    // Find Last
    int start=0, end=n-1, mid, last=-1;
    while(start<=end)
    {
        // mid find karo
        mid=(start+end)/2;
        // arr[mid]==key
        if(arr[mid]==target){
            last=mid;
            start = mid+1;
        }
        // arrr[mid]<key
        else if(arr[mid]<target){
            start=mid+1;
        }
        // arrr[mid]>key
        else{
            end=mid-1;
        }
    }
    return last;
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

    cout<<"First Occurrence of "<<target<<" is at Index: "<<firstOcc(arr,n,target)<<endl;
    cout<<"Last Occurrence of "<<target<<" is at Index: "<<lastOcc(arr,n,target)<<endl;

    // We can also find that how many times the target is occurr in array
    // formula :-  (last position - first position)+1
    cout<<"Tne number of times target occuring in array: "<<(lastOcc(arr,n,target)-firstOcc(arr,n,target))+1;
    return 0;
}