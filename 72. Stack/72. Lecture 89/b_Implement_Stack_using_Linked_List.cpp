#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};
class Stack{
    int size;
    Node *top;
    
    public:
    Stack() {
        top = NULL;
        size = 0;
    }

    // Push
    void push(int value) {
        Node *temp = new Node (value);
        // here we are using heap memory space, but if our heao memory gets full. So to handle this edge case
        if (temp == NULL) {
            cout << "Stack Overflow\n";
            return;
        }
        else {
            temp->next = top;
            top = temp;
            size++;
            cout << "Pushed " << value << " into the stack\n";
        }
    }

    // Pop
    void pop() {
        if (top == NULL) {
            cout << "Stack Underflow\n";
            return;
        }
        else {
            Node *temp = top;
            cout << "Popped " << top->data << " from the stack\n";
            top = top->next;
            delete temp;
            size--;
        }
    }

    // Peek
    int peek() {
        if (top == NULL) {
            cout << "Stack is Empty\n";
            return -1;
        }
        else {
            return top->data;
        }
    }

    // IsEmpty
    bool IsEmpty() {
        return top == NULL;
    }

    // IsSize
    int IsSize(){
        return size;
    }
};

int main() {
    Stack S;
    S.push(6);
    S.push(16);
    S.push(62);
    S.push(86);
    S.pop();
    cout <<S.IsSize() << endl;
    cout << S.peek() << endl;
    cout << S.IsEmpty() << endl;
}