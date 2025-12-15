// GFG
#include<iostream>
using namespace std;

int ways(int arr[], int size, int sum){
    if(sum == 0){
        return 1;
    }
    if(sum < 0){
        return 0;
    }
    int ans = 0; // Here we have use long long because it gives Time Limit Exceed so we solve it with DP
    for(int i = 0; i < size; i++){
        ans+= ways(arr,size,sum-arr[i]);
    }
    return ans;
}

int main(){
    int arr[] = {1,5,6};
    int sum = 7;
    cout << ways(arr,3,sum);

}