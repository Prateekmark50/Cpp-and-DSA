#include<iostream>
using namespace std;
// Method0
int Sum0(int arr0[], int index){
    return arr0[index];
}
// Method 1
int Sum(int arr[], int index, int size){
    // Base Case
    if(index == 5){
        return 0;
    }
    return arr[index]+Sum(arr,index+1,size);
}
// Method 2
int Sum2(int arr2[], int index){
    if(index == -1){
        return 0;
    }
    return arr2[index]+Sum2(arr2,index-1);
}
int main(){
    // Method 0
    int arr0[] = {3,4,1,2,8};
    int total = 0;
    for(int i = 0; i < 5; i++){
        total += Sum0(arr0,i); 
    }
    cout << total << endl;
    
    // Method 1
    int arr[] = {3,4,1,2,8};
    cout << Sum(arr,0,5);

    cout << endl;

    // Method 2
    int arr2[] = {3,4,1,2,8};
    cout << Sum2(arr2,4);
}