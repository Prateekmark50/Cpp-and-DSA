// Leetcode:- Sliding Window Maximum
// Link:- https://leetcode.com/problems/sliding-window-maximum/description/
// Method 2:- Using Deque

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
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> d;
        vector<int> ans;
        int n = nums.size();
        // k-1 elements ko traverse karo
        for (int i = 0; i < k-1; i++) {
            if (d.empty()) {
                d.push_back(i);
            }
            else {
                while (!d.empty() && nums[i] > nums[d.back()]) {
                    d.pop_back();
                }
                d.push_back(i);
            }
        }

        for (int i = k-1; i < n; i++) {
            // Remove smaller element from back
            while (!d.empty() && nums[i] > nums[d.back()]) {
                d.pop_back();
            }
            d.push_back(i);
            // if front element is outside the window, pop
            if (d.front() <= i-k) {
                d.pop_front();
            }
            // Find ans
            ans.push_back(nums[d.front()]);
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
    O(n)
*/ 