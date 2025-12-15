/*
Increasing Order last se means  mai last se chalu karunga bubble soting karna
jo sabse chota element hoga usko piche se aage launga
From 7 4 8 5 3
to 3 4 5 7 8
*/ 

#include<iostream>
using namespace std;
int main(){
    int arr[1000];
    int n; 
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the element of array:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    // For Sorting  the Array
    for(int i=1;i<n;i++)
    {
        bool swapped = 0;
        for(int j=n-1;j>=i;j--)
        {
            if(arr[j]<arr[j-1])
            {
                swap(arr[j],arr[j-1]);
                swapped = 1;
            }
        }
        if(swapped == 0)
        break;
    }
    // For Printing Sort Array
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}