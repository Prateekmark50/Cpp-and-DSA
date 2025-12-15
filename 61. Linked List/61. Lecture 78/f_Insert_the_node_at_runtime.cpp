// Write Code of LinkedList where taking data input from the user at runtime and display all the values at last. 
// then he said here you was adding node at last. 
// now, add node at particular position. (I'm able to solve both the conditions )
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Insert node at the end
void insertAtEnd(Node*& head, int val) {
    Node* newNode = new Node(val);

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert node at a particular position (1-based index)
void insertAtPosition(Node*& head, int val, int pos) {
    Node* newNode = new Node(val);

    if (pos == 1) {  // insert at beginning
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; temp != nullptr && i < pos - 1; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Position out of range!" << endl;
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Display all nodes
void display(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    cout << "Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, val, pos;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        insertAtEnd(head, val);
    }

    cout << "\nInitial Linked List:" << endl;
    display(head);

    cout << "\nEnter value to insert and position: ";
    cin >> val >> pos;
    insertAtPosition(head, val, pos);

    cout << "\nLinked List after insertion:" << endl;
    display(head);

    return 0;
}
