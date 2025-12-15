#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trap(vector<int>&height, int n){
    int leftmax = 0, rightmax = 0, max_height = height[0], water =0, index = 0;
    
    // Max Height Building
    for(int i = 1; i < n; i++){
        if(height[i]>max_height){
            max_height = height[i];
            index = i;
        }
    }

    // left part
    for(int i = 0; i < index; i++){
        if(leftmax > height[i])
        water = water + leftmax - height[i];
        else
        leftmax = height[i];
    }
    // right part
    for(int i = n - 1; i > index; i--){
        if(rightmax > height[i])
        water = water + rightmax - height[i];
        else
        rightmax = height[i];
    }
    return water;
}

int main(){
    int n;
    vector<int> arr(n);
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the element of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"The total water contain is: "<<trap(arr, n);
}