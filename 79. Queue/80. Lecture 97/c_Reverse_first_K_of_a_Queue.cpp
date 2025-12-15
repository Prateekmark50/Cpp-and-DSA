// GFG:- Reverse first K of a Queue
// Link:- https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1

/*
Examples:

Input: q = [1, 2, 3, 4, 5], k = 3
Output: [3, 2, 1, 4, 5]
Explanation: After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5

Input: q = [4, 3, 2, 1], k = 4
Output: [1, 2, 3, 4] 
Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

queue<int> reverseFirstK(queue<int> q, int k) {
    stack<int> st;
    int n = q.size();

    if (k > n || k <= 0) {
        return q;
    }

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push elements from stack into queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining (n - k) elements to back
    for (int i = 0; i < n - k; i++) {
        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    int n, k, val;

    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        q.push(val);
    }

    cout << "Enter value of k: ";
    cin >> k;

    queue<int> ans = reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    }
    cout << endl;

    return 0;
}
