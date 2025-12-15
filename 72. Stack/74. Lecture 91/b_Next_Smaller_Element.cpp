// GFG:- Next Smaller Element
// Link:- https://www.geeksforgeeks.org/problems/immediate-smaller-element1142/1

/*
Examples:

Input: arr[] = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
Explanation: 
The first element smaller than 4 having index > 0 is 2.
The first element smaller than 8 having index > 1 is 5.
The first element smaller than 5 having index > 2 is 2.
There are no elements smaller than 4 having index > 3.
There are no elements smaller than 4 having index > 4.

Input: arr[] = [13, 7, 6, 12]
Output: [7, 6, -1, -1]
Explanation:
The first element smaller than 13 having index > 0 is 7.
The first element smaller than 7 having index > 1 is 6.
There are no elements smaller than 6 having index > 2.
There are no elements smaller than 12 having index > 3.

Input: arr[] = [4, 1]
Output: [1, -1]
Explanation: 4 will be updated to 1 and 1 will be updated to -1.
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerEle(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = 0; i < arr.size(); i++) {
        while (!st.empty() && arr[st.top()] > arr[i]) {
            ans[st.top()] = arr[i];
            st.pop();
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

    vector<int> result = nextSmallerEle(arr);

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