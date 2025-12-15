#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxDiff(vector<int>& arr, int n){
    int suffix = arr[n-1], ans = INT32_MIN;
    for(int i=n-2;i>=0;i--){
        int diff = suffix-arr[i];
        suffix = max(suffix,arr[i]);
        if(ans<diff)
        ans = diff;
    }
    return ans;
    // int suffix = arr[n-1];
    // int ans = -1;

    // for(int i = n-2; i >= 0; i--) {
    //     if (arr[i] < suffix) {
    //         int diff = suffix - arr[i];
    //         ans = max(ans, diff);
    //     }
    //     suffix = max(suffix, arr[i]);
    // }
    // return ans;
}

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout<<"The maximum difference is: "<<maxDiff(arr, n);
    return 0;
}

// int n = nums.size();
        

//         int suffix = nums[n-1];
//         int ans = -1;

//         for(int i = n-2; i >= 0; i--) {
//             if (nums[i] < suffix) {
//                 int diff = suffix - nums[i];
//                 ans = max(ans, diff);
//             }
//             suffix = max(suffix, nums[i]);
//         }
//         return ans;
//     }