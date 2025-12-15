#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *next;
        Node *prev;
        Node (int value) {
            data = value;
            next = NULL;
            prev = NULL;
        }
};

int main() {
    Node *Head = NULL;

    int arr[] = {1,2,3,4,5};

    // Insert at start
    // // Linked List doesn't exist
    // if (Head == NULL) {
    //     Head = new Node(5);
    // }

    // // Alraedy exist
    // else {
    //     Node *temp = new Node(5);
    //     temp->next = Head;
    //     Head->prev = temp;
    //     Head = temp;
    // }

    for (int i = 0; i < 5; i++) {
        // Linked List doesn't exist
        if (Head == NULL) {
            Head = new Node(arr[i]);
        }
        // Alraedy exist
        else {
            Node *temp = new Node(arr[i]);
            temp->next = Head;
            Head->prev = temp;
            Head = temp;
        }
    }
    
    // Print the value
    Node *trav = Head;
    while(trav != NULL){
        cout << trav-> data << " ";
        trav = trav->next;
    }
}