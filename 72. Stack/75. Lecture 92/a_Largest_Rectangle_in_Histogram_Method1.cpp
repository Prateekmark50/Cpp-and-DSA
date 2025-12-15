// Leetcode:- Largest Rectangle in Histogram
// Link:- https://leetcode.com/problems/largest-rectangle-in-histogram/description/
// Merhod 1:- First we find right and left greatest number and transversing array again and again.

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
    // Next Smallest Left
    // Next Smallest Right
    int n = heights.size();
    vector<int> Right(n);
    vector<int> Left(n);

    stack<int> st;

    // Next Smallest Right find karo
    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Right[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Stack ko empty karo
    while (!st.empty()) {
        Right[st.top()] = n;
        st.pop();
    }

    // Next Smallest Left find karo
    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] > heights[i]) {
            Left[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    // Stack ko empty karo
    while (!st.empty()) {
        Left[st.top()] = -1;
        st.pop();
    }

    // Area ko calculate karo
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, heights[i]*(Right[i]-Left[i]-1));
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