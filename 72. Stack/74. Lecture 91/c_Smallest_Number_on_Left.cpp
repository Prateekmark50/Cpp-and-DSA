// GFG:- Smallest Number on left
// Link:- https://www.geeksforgeeks.org/problems/smallest-number-on-left3403/1

/*
Examples:

Input: arr[] = [1, 6, 2]
Output: [-1, 1, 1]
Explaination: 
There is no number to the left of 1, so we return -1. 
After that, the number is 6, and the nearest smaller number on its left is 1. 
Next, the number is 2, and the nearest smaller number on the left is also 1.

Input: arr[] = [1, 5, 0, 3, 4, 5]
Output: [-1, 1, -1, 0, 3, 4]
Explaination: 
There is no number to the left of 1,  so we return -1. 
After that, the number is 5,  and the nearest smaller number on its left is 1. 
Next, the number is 0, and there is no smaller number on the left, so we return -1.
Then comes 3, and the nearest smaller number on its left is 0.
After that, the number is 4, and the nearest smaller number on the left is 3. 
Finally, the number is 5, and the nearest smaller number on its left is 4.
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerEle(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size()-1; i >= 0; i--) {
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