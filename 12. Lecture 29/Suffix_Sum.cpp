#include<iostream>
#include<vector>
using namespace std;

void suffixSum(vector<int> arr , int n){

    vector<int> suffix(n);
    suffix[n-1]=arr[n-1];

    for(int i=n-2;i>=0;i--){
        suffix[i]=suffix[i+1]+arr[i];
    }
    cout<<"The Suffix Sum array of given array is: ";
    for(int i = 0; i < n; i++){
        cout<<suffix[i]<<" ";
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
    
    suffixSum(arr, n);
}