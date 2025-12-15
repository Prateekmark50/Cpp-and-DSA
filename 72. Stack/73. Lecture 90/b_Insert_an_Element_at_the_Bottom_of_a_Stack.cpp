// Leetcode :- Insert an Element at the Bottom of a Stack
// Link:- https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1?page=2&category=Stack&difficulty=Easy&sortBy=submissions

/*
Example 1:

Input:
n = 5
x = 2
st = {4,3,2,1,8}
Output:
{2,4,3,2,1,8}
Explanation:
After insertion of 2, the final stack will be {2,4,3,2,1,8}.

Example 2:

Input:
n = 3
x = 4
st = {5,3,1}
Output:
{4,5,3,1}
Explanation:
After insertion of 4, the final stack will be {4,5,3,1}.
*/ 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

stack<int> insertAtBottom(stack<int> st, int x) {
    stack<int> temp;
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!temp.empty()) {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

int main() {
    stack<int> st;
    int n, value, x;
    
    cout << "Enter the number of elements in the stack: ";
    cin >> n;
    cout << "Enter the elements (top to bottom):\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        st.push(value);
    }
    
    cout << "Enter the value to insert at the bottom: ";
    cin >> x;

    st = insertAtBottom(st, x);

    cout << "Stack after inserting at the bottom (top to bottom):\n";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
/*
Time Complexity:
    O(N)
Space Complexity:
    O(N)
*/