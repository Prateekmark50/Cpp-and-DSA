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

    // Print the Doubly Linked List
    Node *trav = Head;
    while (trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}