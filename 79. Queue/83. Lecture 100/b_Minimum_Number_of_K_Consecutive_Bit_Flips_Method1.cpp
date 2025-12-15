// Leetcode:- Minimum Number of K Consecutive Bit Flips
// Link:- https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/
// Method 1: - Brute Froce Approach( But time limt exceeded)

/*
Example 1:

Input: nums = [0,1,0], k = 1
Output: 2
Explanation: Flip nums[0], then flip nums[2].

Example 2:

Input: nums = [1,1,0], k = 2
Output: -1
Explanation: No matter how we flip subarrays of size 2, we cannot make the array become [1,1,1].

Example 3:

Input: nums = [0,0,0,1,0,1,1,0], k = 3
Output: 3
Explanation: 
Flip nums[0],nums[1],nums[2]: nums becomes [1,1,1,1,0,1,1,0]
Flip nums[4],nums[5],nums[6]: nums becomes [1,1,1,1,1,0,0,0]
Flip nums[5],nums[6],nums[7]: nums becomes [1,1,1,1,1,1,1,1]
*/ 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flip = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                if (i + k - 1 >= n) {
                    return -1;
                }
                for (int j = i; j <= i + k - 1; j++) {
                    nums[j] = !nums[j];
                }
                flip++;
            }
        }
        return flip;
    }
};

int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter array elements (0 or 1): ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    Solution obj;
    int result = obj.minKBitFlips(nums, k);

    cout << "\nMinimum K-bit flips required: " << result << endl;

    return 0;
}
/*
Time Complexity:- 
    O(n * k)
Space Complexity:- 
    O(1)
*/ 