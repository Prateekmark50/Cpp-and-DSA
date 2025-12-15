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

    // Delete the node at given position
    int pos = 3;

    // delete at start
    if (pos == 1) {
        // If only one node exist
        if (Head->next == NULL) {
            delete Head;
            Head = NULL;
        }
        // If more than one node exist
        else {
            Node *temp = Head;
            Head = Head->next;
            delete temp;
            Head->prev = NULL;
        }
    }
    // Delete at end or at middle
    else {
        Node *curr = Head;
        // Go to the node, which we have to delete
        while (--pos) {
            curr = curr->next;
        }

        // delete at end
        if (curr->next == NULL) {
            curr->prev->next = NULL;
            delete curr;
        }

        // delete at middle
        else {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            delete curr;
        }
    }

    // Print the Doubly Linked List
    Node *trav = Head;
    while (trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}