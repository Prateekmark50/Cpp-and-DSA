// GFG:- Next Greater Element in Circular Array
// Link:- https://www.geeksforgeeks.org/problems/next-greater-element/1

/*
Examples: 

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation:
The next greater element for 1 is 3.
The next greater element for 3 is 4.
The next greater element for 2 is 4.
The next greater element for 4 does not exist, so return -1.

Input: arr[] = [0, 2, 3, 1, 1]
Output: [2, 3, -1, 2, 2]
Explanation:
The next greater element for 0 is 2.
The next greater element for 2 is 3.
The next greater element for 3 does not exist, so return -1.
The next greater element for 1 is 2 (from circular traversal).
The next greater element for 1 is 2 (from circular traversal).
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreater(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, -1);

    for (int i = 0; i < 2*n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i % n]) {
            ans[st.top()] = arr[i % n];
            st.pop();
        }
        st.push(i % n);
        // or we can also write
        // if (i < n) {
        //     st.push(i);
        // }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> result = nextGreater(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
}
/*
Time Complexity:- 
    O(n)
Space Complexity:-
    O(n)
*/ 