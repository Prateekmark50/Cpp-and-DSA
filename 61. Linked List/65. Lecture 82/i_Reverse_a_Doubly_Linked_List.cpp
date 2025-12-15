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

Node* reverseDLL(Node* Head) {
    Node *curr = Head, *previous = NULL, *fut = NULL;
    while (curr) {
        fut = curr->next;
        curr->next = previous;
        curr->prev = fut;
        previous = curr;
        curr = fut;
    }
    Head = previous;
    return Head;
}

int main() {
    Node* Head = NULL;

    // Create the Doubly Linked List
    int arr[] = {1,2,3,4,5};

    Head = createDoublyLinkedList(arr, 0, 5, Head);

    // Print the Doubly Linked List Before Reversing
    Node *trav;
    trav = Head;
    cout << "Before Reversing the Linked List:" <<endl;
    while(trav){
        cout << trav->data << " ";
        trav = trav->next;
    }
    cout <<endl;

    // Reverse the linked list
    Head = reverseDLL(Head);

    // Print the Doubly Linked List After Reversing
    trav = Head;
    cout << "After Reversing the Linked List:" <<endl;
    while (trav) {
        cout << trav->data << " ";
        trav = trav->next;
    }
}