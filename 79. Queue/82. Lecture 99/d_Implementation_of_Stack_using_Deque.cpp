#include <iostream>
#include <deque>
using namespace std;

class Stack{
    deque<int> d;
public:
    void push(int x) {
        d.push_back(x);
        cout << "Pushed " << x << " into the stack\n";
        return;
    }
    void pop() {
        int element = d.back();
        cout << "Popped " << element << " from the stack\n";
        d.pop_back();
        return;
    }
    void top() {
        cout << "Top element of stack is " << d.back();
        return;
    }
    void IsEmpty() {
        if (d.empty()) {
            cout << "Stack is empty\n";
        }
        else {
            cout << "Stack is not empty\n";
        }
    }
    void IsSize() {
        cout << "Size of stack is " << d.size();
        return;
    }
};

int main() {
    Stack S;
    S.push(5);
    S.push(6);
    S.push(7);
    S.IsEmpty();
    S.IsSize();
    S.top();
}