#include<iostream>
using namespace std;

void fun(int a[], int n){
    cout<<sizeof(a)<<endl;
    for(int i=0;i<5;i++){
        cout<<a[i]<<" ";
    }
}

int main(){
    int arr[5]={3,2,1,6,7};//This arr[] is original array instead of a[] which is mention in function  
    cout<<"The size of array is:"<<sizeof(arr)<<endl;
    fun(arr,5);
}