// GFG:- Max of min for every window size
// Link:- https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1
// Method 1:- Ye method brute force hai, aur ye sare test case handle nahi kar payega

/*
Examples :

Input: arr[] = [10, 20, 30, 50, 10, 70, 30]
Output: [70, 30, 20, 10, 10, 10, 10] 
Explanation: 
Window size 1: minimums are [10, 20, 30, 50, 10, 70, 30], maximum of minimums is 70.
Window size 2: minimums are [10, 20, 30, 10, 10, 30], maximum of minimums is 30.
Window size 3: minimums are [10, 20, 10, 10, 10], maximum of minimums is 20.
Window size 4–7: minimums are [10, 10, 10, 10], maximum of minimums is 10.

Input: arr[] = [10, 20, 30]
Output: [30, 20, 10]
Explanation: 
Window size 1: minimums of  [10], [20], [30], maximum of minimums is 30.
Window size 2: minimums of [10, 20], [20,30], maximum of minimums is 20.
Window size 3: minimums of [10,20,30], maximum of minimums is 10.
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> maxOfMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            int num = INT32_MAX;
            for (int k = j; k < j+i+1; k++) {
                num = min(num, arr[k]);
            }
            ans[i] = max(ans[i], num);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the element of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = maxOfMins(arr);
    cout << "Result: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}