// GFG:- Queue Reversal
// Link:- https://www.geeksforgeeks.org/problems/queue-reversal/1

/*
Examples:

Input: q[] = [5, 10, 15, 20, 25]
Output: [25, 20, 15, 10, 5]
Explanation: After reversing the given elements of the queue, the resultant queue will be 25 20 15 10 5.

Input: q[] = [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
Explanation: After reversing the given elements of the queue, the resultant queue will be 5 4 3 2 1.
*/

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        stack<int> st;
        // empty the queue
        while (!q.empty()) {
            st.push(q.front());
            q.pop();
        }
        // empty the stack
        while (!st.empty()) {
            q.push(st.top());
            st.pop();
        }
    }
};

int main() {
    int n;
    cout << "Enter number of elements in queue: ";
    cin >> n;

    queue<int> q;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    Solution obj;
    obj.reverseQueue(q);

    cout << "Reversed Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
