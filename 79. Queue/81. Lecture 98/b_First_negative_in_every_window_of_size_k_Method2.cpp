// GFG:- First negative in every window of size k
// Link:- https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1
// Method2:- 

/*
Examples:

Input: arr[] = [-8, 2, 3, -6, 10] , k = 2
Output: [-8, 0, -6, -6]
Explanation:
Window [-8, 2] First negative integer is -8.
Window [2, 3] No negative integers, output is 0.
Window [3, -6] First negative integer is -6.
Window [-6, 10] First negative integer is -6.

Input: arr[] = [12, -1, -7, 8, -15, 30, 16, 28] , k = 3
Output: [-1, -1, -7, -15, -15, 0] 
Explanation:
Window [12, -1, -7] First negative integer is -1.
Window [-1, -7, 8] First negative integer is -1.
Window [-7, 8, -15] First negative integer is -7.
Window [8, -15, 30] First negative integer is -15.
Window [-15, 30, 16] First negative integer is -15.
Window [30, 16, 28] No negative integers, output is 0.

Input: arr[] = [12, 1, 3, 5] , k = 3
Output: [0, 0] 
Explanation:
Window [12, 1, 3] No negative integers, output is 0.
Window [1, 3, 5] No negative integers, output is 0.
*/ 

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();
        queue<int> q;

        // push first k-1 negative elements in queue
        for (int i = 0; i < k - 1; i++) {
            if (arr[i] < 0) {
                q.push(i);
            }
        }
        
        for (int i = k - 1; i < n; i++) {
            // push negative number
            if (arr[i] < 0) {
                q.push(i);
            }
            if (q.empty()) {
                ans.push_back(0);
            }
            else {
                // check if first index of queue lies inside the window 
                if (q.front() <= i-k) {
                    q.pop();
                }
                if (q.empty()) {
                    ans.push_back(0);
                }
                else {
                    ans.push_back(arr[q.front()]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;

    int n, k;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter window size k: ";
    cin >> k;

    vector<int> result = sol.firstNegInt(arr, k);

    cout << "\nFirst negative integers in every window of size " << k << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Time Complexity:- O(n)
*/ 