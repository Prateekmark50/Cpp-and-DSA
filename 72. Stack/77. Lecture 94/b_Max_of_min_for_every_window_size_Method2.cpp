// GFG:- Max of min for every window size
// Link:- https://www.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size3453/1

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
    stack<int> st;
    vector<int> ans(n, 0);
    int index;
    int range;

    for (int i = 0; i < n; i++) {
        // Value kab tak pop hogi
        // NSL NSR
        while (!st.empty() && arr[st.top()] > arr[i]) {
            index = st.top();
            st.pop();

            // i = next smallest right
            // Stack ke andar jo index, NSL
            if (!st.empty()) {
                range = i - st.top() - 1; // Maximum window size
                ans[range-1] = max(ans[range-1], arr[index]);
            }
            else {
                range = i; // Maximum window size
                ans[range-1] = max(ans[range-1], arr[index]);
            }
        }
        st.push(i);
    }

    // Stack ko khaali karo
    while (!st.empty()) {
        index = st.top();
        st.pop();

        // i = next smallest right
        // Stack ke andar jo index, NSL
        if (!st.empty()) {
            range = n - st.top() - 1; // Maximum window size
            ans[range-1] = max(ans[range-1], arr[index]);
        }
        else {
            range = n; // Maximum window size
            ans[range-1] = max(ans[range-1], arr[index]);
        }
    }

    // ans array ki value ko update kar do
    for (int i = n-2; i >= 0; i--) {
        ans[i] = max(ans[i], ans[i+1]); 
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