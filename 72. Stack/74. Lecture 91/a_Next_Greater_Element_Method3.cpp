// GFG:- Next Greater Element
// Link:- https://www.geeksforgeeks.org/problems/next-larger-element-1587115620/1
// Method 3:- using stack to store element but this time we start from last of array

/*
Examples

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.

Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.

Input: arr[] = [1, 2, 3, 5]
Output: [2, 3, 5, -1]
Explanation: For a sorted array, the next element is next greater element also except for the last element.

Input: arr[] = [5, 4, 3, 1]
Output: [-1, -1, -1, -1]
Explanation: There is no next greater element for any of the elements in the array, so all are -1.
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size()-1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            st.pop();
        }
        if (!st.empty()) {
            ans[i] = arr[st.top()];
        }
        st.push(i);
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

    vector<int> result = nextLargerElement(arr);

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