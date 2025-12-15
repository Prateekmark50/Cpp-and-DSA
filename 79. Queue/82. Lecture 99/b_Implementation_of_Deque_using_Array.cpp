#include <iostream>
using namespace std;

class Deque{
    int front, rear, size;
    int *arr;
public:
    Deque(int n) {
        size = n;
        arr = new int[n];
        front = rear = -1;
    }

    bool IsEmpty() {
        return front == -1;
    }

    bool IsFull() {
        return (rear+1)%size == front;
    }

    void push_front(int x) {
        // Empty
        if (IsEmpty()) {
            front = rear = 0;
            cout << "Pushed " << x << " in front of deque\n";
            arr[0] = x;
            return;
        }
        // Full
        else if (IsFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        // Normal
        else {
            front = (front-1+size)%size;
            arr[front] = x;
            cout << "Pushed " << x << " in front of deque\n";
            return;
        }
    }

    void push_back(int x) {
        // Empty
        if (IsEmpty()) {
            front = rear = 0;
            cout << "Pushed " << x << " in back of deque\n";
            arr[0] = x;
            return;
        }
        // Full
        else if (IsFull()) {
            cout << "Deque Overflow\n";
            return;
        }
        // Normal
        else {
            rear = (rear+1)%size;
            arr[rear] = x;
            cout << "Pushed " << x << " in back of deque\n";
            return;
        }
    }

    void pop_front() {
        // Empty
        if (IsEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        else {
            cout << "Popped " << arr[front] << " from back of deque\n";
            // Single Element
            if (front == rear) {
                front = rear = -1;
            }
            // more than 1 element
            else {
                front = (front+1)%size;
            }
        }
    }

    void pop_back() {
        // Empty
        if (IsEmpty()) {
            cout << "Deque Underflow\n";
            return;
        }
        else {
            cout << "Popped " << arr[rear] << " from back of deque\n";
            // Single Element
            if (front == rear) {
                front = rear = -1;
            }
            // more than 1 element
            else {
                rear = (rear-1+size)%size;
            }
        }
    }

    int start() {
        if (IsEmpty()) {
            return -1;
        }
        else {
            return arr[front];
        }
    }

    int end() {
        if (IsEmpty()) {
            return -1;
        }
        else {
            return arr[rear];
        }
    }
};

int main() {
    Deque d(5);
    // d.push_back(10);
    // d.push_back(9);
    // d.push_front(13);
    // d.push_back(9);
    // d.push_front(13);
    // // d.push_back(9);
    // // d.push_front(13);
    // d.pop_back();
    // d.pop_front();
    // cout << d.start() << endl;

    d.push_back(10);
    d.push_back(91);
    d.push_back(9);
    d.push_front(18);
    d.pop_back();
    d.pop_front();
    cout << d.start() << endl;
}