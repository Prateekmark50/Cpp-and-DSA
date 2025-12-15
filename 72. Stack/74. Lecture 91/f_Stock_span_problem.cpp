// GFG:- Stock span problem
// Link:- https://www.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

/*
Examples:

Input: arr[] = [100, 80, 90, 120]
Output: [1, 1, 2, 4]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more days behind it so the span is 1, 
80 is greater than equal to 80 and smaller than 100 so the span is 1, 
90 is greater than equal to 90 and 80 so the span is 2, 
120 is greater than 90, 80 and 100 so the span is 4. 
So the output will be [1, 1, 2, 4].

Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 10 is greater than equal to 10 and there are no more days behind it so the span is 1, 
4 is greater than equal to 4 and smaller than 10 so the span is 1, 
5 is greater than equal to 4 and 5 and smaller than 10 so the span is 2, 
and so on. Hence the output will be [1, 1, 2, 4, 5, 1].

Input: arr[] = [100, 80, 55, 70, 60, 75, 85]
Output: [1, 1, 1, 2, 1, 4, 6]
*/ 

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextSmallerEle(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n, 1);

    for (int i = n-1; i >= 0; i--) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            ans[st.top()] = st.top() - i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = st.top() + 1;
        st.pop();
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