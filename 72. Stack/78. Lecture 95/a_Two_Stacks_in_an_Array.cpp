// GFG:- Two Stacks in an Array
// Link:- https://www.geeksforgeeks.org/problems/implement-two-stacks-in-an-array/1
// Method:- we start filling array from start and end, means starting from the endpoints

/*
Examples:

Input:
push1(2)
push1(3)
push2(4)
pop1()
pop2()
pop2()
Output: [3, 4, -1]
Explanation: 
push1(2): the stack1 will be [2]
push1(3): the stack1 will be [2,3]
push2(4): the stack2 will be [4]
pop1(): the poped element will be 3 from stack1 and stack1 will be {2}
pop2(): the poped element will be 4 from stack2 and now stack2 is empty
pop2(): the stack2 is now empty hence returned -1.

Input:
push1(1)
push2(2)
pop1()
push1(3)
pop1()
pop1()
Output: [1, 3, -1]
Explanation:
push1(1): the stack1 will be [1]
push2(2): the stack2 will be [2]
pop1(): the poped element will be 1 from stack1 and stack1 will be empty
push1(3): the stack1 will be [3]
pop1(): the poped element will be 3 from stack1 and stack1 will be empty
pop1(): the stack1 is now empty hence returned -1.

Input:
push1(2)
push1(3)
push1(4)
pop2()
pop2()
pop2()
Output: [-1, -1, -1]
Explanation:
push1(2): the stack1 will be [2]
push1(3): the stack1 will be [2,3]
push1(4): the stack1 will be [2,3,4]
pop2(): the stack2 is empty hence returned -1.
pop2(): the stack2 is empty hence returned -1.
pop2(): the stack2 is empty hence returned -1.
*/ 

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class twoStacks {
  public:
    int *arr;
    int size;
    int top1, top2;
    
    twoStacks(int n = 100) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    // Push in Stack1
    void push1(int x) {
        if (top1 + 1 == top2) return; // Overflow
        top1++;
        arr[top1] = x;
    }

    // Push in Stack2
    void push2(int x) {
        if (top2 - 1 == top1) return; // Overflow
        top2--;
        arr[top2] = x;
    }

    // Pop from Stack1
    int pop1() {
        if (top1 == -1) return -1;
        int element = arr[top1];
        top1--;
        return element;
    }

    // Pop from Stack2
    int pop2() {
        if (top2 == size) return -1;
        int element = arr[top2];
        top2++;
        return element;
    }
};

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    twoStacks ts(n);

    int q;
    cout << "Enter number of operations: ";
    cin >> q;

    vector<int> output;
    cout << "Enter operations (push1 x / push2 x / pop1 / pop2):" << endl;

    while (q--) {
        string op;
        cin >> op;

        if (op == "push1") {
            int x; cin >> x;
            ts.push1(x);
        } else if (op == "push2") {
            int x; cin >> x;
            ts.push2(x);
        } else if (op == "pop1") {
            output.push_back(ts.pop1());
        } else if (op == "pop2") {
            output.push_back(ts.pop2());
        }
    }

    cout << "Output: [ ";
    for (int val : output) cout << val << " ";
    cout << "]" << endl;

    return 0;
}
