// Leetcode:- Sliding Window Maximum
// Link:- https://leetcode.com/problems/sliding-window-maximum/description/
// Method 1:- Brute Force Approach (But time Limit Exceed)

/*
Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]
*/ 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            int total = INT_MIN;
            for (int j = i; j < i + k; j++) {
                total = max(total, nums[j]);
            }
            ans.push_back(total);
        }

        return ans;
    }
};

int main() {
    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter window size (k): ";
    cin >> k;

    Solution obj;
    vector<int> result = obj.maxSlidingWindow(nums, k);

    cout << "\nMaximum in each sliding window: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
Time Complexity:- 
    O(n-k)* O(k) => O(nk-k^2)=> O(n * k)
*/ 