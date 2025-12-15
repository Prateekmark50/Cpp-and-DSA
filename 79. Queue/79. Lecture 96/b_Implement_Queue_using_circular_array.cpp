#include <iostream>
using namespace std;

// Implement queue using circular array, circular queue
class Queue{
    int *arr;
    int front, rear, size;

public:

    // Constructor
    Queue(int n) {
        arr = new int [n];
        size = n;
        front = rear = -1;
    }

    // If queue is empty or not
    bool IsEmpty() {
        return front == -1;
    }

    // Queue is full or not
    bool IsFull() {
        return (rear+1) % size == front;
    }

    // Push element into queue at end
    void push(int x) {
        // Empty
        if (IsEmpty()) {
            cout << "Pushed " << x << " into the Queue\n";
            front = rear = 0;
            arr[0] = x;
            return;
        }
        // Full
        else if (IsFull()) {
            cout << "Queue Overflow\n";
            return;
        }
        // Insert
        else {
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << "Pushed " << x << " into the Queue\n";
        }
    }

    // Pop element at starting
    void pop() {
        // Empty
        if (IsEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }
        // pop kar do
        else {
            if (front == rear) {
                cout << "Popped " << arr[front] << " into the Queue\n";
                front = rear = -1;
            }
            else {
                cout << "Popped " << arr[front] << " into the Queue\n";
                front = (front + 1) % size;
            }
        }
    }

    // start mein konsa element rakha hai
    int start() {
        if (IsEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        else {
            return arr[front];
        }
    }
};

int main() {
    Queue q(5);
    q.push(5);
    q.push(15);
    q.push(51);
    q.push(125);
    q.pop();
    q.push(511);
    q.push(38);
    q.pop();
}