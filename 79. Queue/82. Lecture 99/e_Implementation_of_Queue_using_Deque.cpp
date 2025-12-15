#include <iostream>
#include <deque>
using namespace std;

class Queue{
    deque<int> d;
public:
    void push(int x) {
        d.push_back(x);
        cout << "Pushed " << x << " into the queue\n";
        return;
    }
    void pop() {
        int element = d.front();
        cout << "Popped " << element << " from the queue\n";
        d.pop_front();
        return;
    }
    void start() {
        cout << "Front element of queue is " << d.front();
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
    Queue q;
    q.push(5);
    q.push(6);
    q.push(7);
    q.IsEmpty();
    q.IsSize();
    q.start();
}