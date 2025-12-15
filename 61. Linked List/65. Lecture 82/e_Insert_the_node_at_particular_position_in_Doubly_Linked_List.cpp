#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *prev;

        Node(int value){
            data = value;
            next = NULL;
            prev = NULL;
        }
};

Node* createDoublyLinkedList(int arr[], int index , int size, Node *back) {
    // Base Case
    if (index == size) {
        return NULL;
    }
    Node* temp = new Node(arr[index]);
    temp->prev = back;
    temp->next = createDoublyLinkedList(arr, index+1, size, temp);

    return temp;
}

int main() {
    Node* Head = NULL;

    // Create the Doubly Linked List
    int arr[] = {1,2,3,4,5};

    Head = createDoublyLinkedList(arr, 0, 5, Head);

    // Insert the node at given position
    int pos = 2;

    // insert at start
    if (pos == 0) {
        // Linked exist nahi karti hai
        if (Head == NULL) {
            Head = new Node(5);
        }
        // Linked exist karti hai
        else {
            Node *temp = new Node(5);
            temp->next = Head;
            Head->prev = temp;
            Head = temp;
        }
    }
    // Insert at end or at middle
    else {
        Node *curr = Head;
        // Go to the node, after which I have to insert
        while (--pos) {
            curr = curr->next;
        }

        // insert at end
        if (curr->next == NULL) {
            Node *temp = new Node(5);
            temp->prev = curr;
            curr->next = temp;
        }

        // insert at middle
        else {
            Node *temp = new Node(5);
            temp->next = curr->next;
            temp->prev = curr;
            curr->next = temp;
            temp->next->prev = temp;
        }
    }

    // Print the Doubly Linked List
    Node *trav = Head;
    while (trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}