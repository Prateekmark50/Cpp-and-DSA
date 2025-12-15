#include<iostream>
using namespace std;
// Method 0
int minElement0(int arr0[], int index){
    return arr0[index];
}
// Method 1
int minElement(int arr[], int index, int size){
    if(index == size-1){
        return arr[index];
    }
    return min(arr[index],minElement(arr, index+1, size)); 
}

int main(){
    // Method 0
    int arr0[] = {3,4,1,2,8};
    int num = arr0[0];
    for(int i = 0; i < 5; i++){
        num = min(num,minElement0(arr0,i));
    }
    cout << num << endl;

    // Method 1
    int arr[] = {7,2,4,1,6};
    cout << minElement(arr,0,5);
}