#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *prev;
        Node *next;
        Node(int value) {
            data = value;
            prev = NULL;
            next = NULL;
        }
};

Node* createDoublyLinkedList(int arr[], int index , int size, Node *previous) {
    // Base Case
    if (index == size) {
        return previous;
    }
    Node* temp = new Node(arr[index]);
    temp->next = previous;
    if (previous) {
        previous->prev = temp; 
    }
    
    return createDoublyLinkedList(arr, index+1, size, temp);
}

int main() {
    Node* Head = NULL;

    // Create the Doubly Linked List
    int arr[] = {1,2,3,4,5};

    Head = createDoublyLinkedList(arr, 0, 5, Head);

    // Print the Doubly Linked List
    Node *trav = Head;
    while (trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}