#include<iostream>
using namespace std;
// Print the Array using Triple Argument
void print(int arr[], int index, int size){
    // Base Case
    if(index == size){
        return;
    }
    
    cout << arr[index] << " ";
    print(arr,index+1,size);
}
// Print the Array using Triple Argument
void print1(int arr1[], int index, int size){
    // Base Case
    if(index == size){
        return;
    }
    
    print1(arr1,index+1,size);
    cout << arr1[index] << " ";
}
// Print the Array using Double Argument
void print2(int arr2[], int index){
    // Base Case
    if(index == -1){
        return;
    }
    
    cout << arr2[index] << " ";
    print2(arr2,index-1);
    
}
// Print the Array using Double Argument
void print3(int arr3[], int index){
    // Base Case
    if(index == -1){
        return;
    }
    print3(arr3,index-1);
    cout << arr3[index] << " ";
}

int main(){
    // Print the Array using Triple Argument
    int arr[] = {3,4,1,2,8};
    print(arr,0,5);

    cout << endl;

    int arr1[] = {3,4,1,2,8};
    print1(arr1,0,5);

    cout << endl;

    // Print the Array using Double Argument
    int arr2[] = {3,4,1,2,8};
    print2(arr2,4);

    cout << endl;

    int arr3[] = {3,4,1,2,8};
    print3(arr3,4);
}