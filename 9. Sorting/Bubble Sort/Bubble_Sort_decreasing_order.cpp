/*
    Bubble Sort in decreasing order
    From 1 4 2 3 5
    to 5 4 3 2 1
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
    for(int i=n-2;i>=0;i--)
    {
        bool swapped = 0;
        for(int j =0;j<=i;j++)
        {
            if(arr[j]<arr[j+1])//--> here I had made changes to make it in decreasing order
            {
                swap(arr[j],arr[j+1]);
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