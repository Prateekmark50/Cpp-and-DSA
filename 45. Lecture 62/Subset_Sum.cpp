#include<iostream>
#include<vector>
using namespace std;

void subsetSum(int arr[], int index, int n, int sum, vector<int> &ans){
    if(index == n){
        ans.push_back(sum);
        return;
    }
    // Not included
    subsetSum(arr,index+1,n,sum,ans);
    // Included
    subsetSum(arr,index+1,n,sum+arr[index],ans);
}

int main(){
    int arr[] = {1,2,3,4};
    vector<int> ans;
    subsetSum(arr,0,4,0,ans);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
}
/*
Time Complexity:-
    O(2^(n+1)-1) => O(2^n)
Space Complexity:-
    O(n)
*/ 