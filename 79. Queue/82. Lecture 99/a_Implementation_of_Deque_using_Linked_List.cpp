#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node (int value) {
        data = value;
        prev = NULL;
        next = NULL;
    }
};

class Deque{
    Node *front, *rear;
public:
    Deque() {
        front = rear = NULL;
    }

    // push-front
    void push_front(int x) {
        // Empty
        if (front == NULL) {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in front of deque\n";
            return;
        }
        // Not Empty
        else {
            Node *temp = new Node(x);
            temp->next = front;
            front->prev = temp;
            front = temp;
            cout << "Pushed " << x << " in front of deque\n";
            return;
        }
    }

    // push_back
    void push_back(int x) {
        // Empty
        if (front == NULL) {
            front = rear = new Node(x);
            cout << "Pushed " << x << " in back of deque\n";
            return;
        }
        // Not Empty
        else {
            Node *temp = new Node(x);
            rear->next = temp;
            temp->prev = rear;
            rear = temp;
            cout << "Pushed " << x << " in back of deque\n";
            return;
        }
    }

    // pop front
    int pop_front() {
        if (front == NULL) {
            cout << "Deque Underflow\n";
            return -1;
        }
        else {
            Node *temp = front;
            cout << "Popped " << temp->data << " from front of deque\n";
            front = front->next;
            delete temp;
            // more than 1 node
            if (front) {
                front->prev = NULL;
            }
            // only 1 node
            else {
                rear = NULL;
            }
        }
    }

    // pop back
    int pop_back() {
        if (front == NULL) {
            cout << "Deque Underflow\n";
            return -1;
        }
        else {
            Node *temp = rear;
            cout << "Popped " << temp->data << " from back of deque\n";
            rear = rear->prev;
            delete temp;
            // more than 1 node
            if (rear) {
                rear->next = NULL;
            }
            // only 1 node
            else {
                front = NULL;
            }
        }
    }

    // start
    int start() {
        if (front == NULL) {
            return -1;
        }
        else {
            return front->data;
        }
    }

    // end
    int end() {
        if (front == NULL) {
            return -1;
        }
        else{
            return rear->data;
        }
    }
};

int main() {
    Deque d;
    d.push_back(5);
    d.push_front(8);
    // d.pop_back();
    // cout << d.start() << endl;
    cout << d.end() << endl;
    d.pop_back();
    d.pop_back();
    d.pop_back();
}