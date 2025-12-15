#include <iostream>
using namespace std;

// Implement Queue using Linked List
class Node {
    public:
    int data;
    Node *next;
    Node (int value) {
        data = value;
        next = NULL;
    }
};

class Queue {
    Node *front;
    Node *rear;

    public:

    // Constructor
    Queue() {
        front = rear = NULL;
    }

    // Queue is empty or not
    bool IsEmpty() {
        return front == NULL;
    }

    // Push element into the queue
    void push(int x) {
        // Empty
        if (IsEmpty()) {
            cout << "Pushed " << x << " element into the queue\n";
            front = rear = new Node(x);
            return;
        }

        // Empty nahi hai
        else {
            rear->next = new Node(x);
            if (rear->next == NULL) {
                cout << "Queue Oveerflow\n";
                return;
            } 
            cout << "Pushed " << x << " element into the queue\n";
            rear = rear->next;
        }
    }

    // Pop element from the queue
    void pop() {
        // Empty toh nahi hai
        if (IsEmpty()) {
            cout << "Queue is Underflow\n";
            return;
        }
        else {
            cout << "Popped " << front->data << " element from the queue\n";
            Node *temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Starting element in the queue
    int start() {
        if (IsEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        else {
            return front->data;
        }
    }
};

int main() {
    Queue q;
    q.push(5);
    q.push(51);
    q.push(115);
    q.push(58);
    q.pop();
    cout << q.start();
}