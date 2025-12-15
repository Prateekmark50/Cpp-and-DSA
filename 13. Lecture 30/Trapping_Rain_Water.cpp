#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int trap(vector<int>&height, int n){
    int left_max[n], right_max[n];
    left_max[0] = 0;
    for(int i = 1; i < n; i++){
        left_max[i] = max(left_max[i - 1], height[i - 1]);
    }
    right_max[n - 1] = 0;
    for(int i = n - 2; i >= 0; i--){
        right_max[i] = max(right_max[i + 1], height[i + 1]);
    }
    int waterTrapped = 0;
    for(int i = 0; i < n; i++){
        int min_height = min(left_max[i], right_max[i]);
        if(min_height - height[i] >= 0){
            waterTrapped = waterTrapped + min_height - height[i];
        }
    }
    return waterTrapped;
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