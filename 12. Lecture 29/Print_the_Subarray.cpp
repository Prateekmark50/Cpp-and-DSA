#include<iostream>
#include<vector>
using namespace std;

void printSubarrays(vector<int>&arr , int n){    //n = arr.size();
    
    for(int size=1;size<=n;size++){
        cout<<"The "<<size<<" size of subarray: "<<endl;
        for(int start=0;start<=n-size;start++){
            for(int i=start;i<start+size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
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
    cout<<"The subarray of given array is:"<<endl;
    printSubarrays(arr,n);
}