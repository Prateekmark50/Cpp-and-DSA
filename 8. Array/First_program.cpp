#include<iostream>
using namespace std;

int main()
{
    // To display the array
    int arr[4]={1,2,3,4};
    for(int i=0;i<4;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    // One more way to display array
    int arr1[]={1,2,3,4};
    for(int i=0;i<4;i++){
        cout<<arr1[i]<<" ";
    } 
    cout<<endl;

    // Another way by taking input from user 
    int size;
    cout<<"Enter the size of array:";
    cin>>size;

    // int arr[size];  --> ye run karega par size ki jagaha value rahana sahi approach hai 
    int arr2[1000];//--> yaha par mene size ki jagaha 1000 value dal di kyuki ye ek galat tarika hai

    for(int i=0;i<size;i++){
        cin>>arr2[i];
    }

    for(int i=0;i<size;i++){
        cout<<arr2[i]<<" ";
    }
}