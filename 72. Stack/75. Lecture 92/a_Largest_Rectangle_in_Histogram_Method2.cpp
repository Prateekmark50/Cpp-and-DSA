// Leetcode:- Largest Rectangle in Histogram
// Link:- https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Method 2:- Transversing the array just once to solve problem

/*
Example 1:

Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:

Input: heights = [2,4]
Output: 4
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    int ans = 0;
    int index;
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            index = st.top();
            st.pop();

            if (!st.empty()) {
                ans = max(ans, heights[index]*(i-st.top()-1));
            }
            else {
                ans = max(ans, heights[index]*i);
            }
        }
        st.push(i);
    }

    while (!st.empty()) {
        index = st.top();
        st.pop();

        if (!st.empty()) {
            ans = max(ans, heights[index]*(n-st.top()-1));
        }
        else {
            ans = max(ans, heights[index]*n);
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of element bars in histogram: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter heights of bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    cout << "Largest Rectangle Area = " << largestRectangleArea(heights) << endl;
}
/*
Time Complexity:- 
    O(n)
Space Complexity:-
    O(n)
*/ 