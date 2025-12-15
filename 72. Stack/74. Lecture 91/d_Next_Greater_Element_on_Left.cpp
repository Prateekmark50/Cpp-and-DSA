/*
Input: arr[] = [1, 5, 0, 3, 4, 5]
Output: [-1, -1, 5, 5, 5, -1]
*/ 
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    stack<int> st;
    vector<int> ans(arr.size(), -1);

    for (int i = arr.size()-1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
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

    vector<int> result = nextGreaterElement(arr);

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