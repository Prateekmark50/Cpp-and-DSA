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
    Node *Head = NULL, *Tail = NULL;

    int arr[] = {1,2,3,4,5};

    // Insert at end
    for (int i = 0; i < 5; i++) {
        // Linked List doesn't exist
        if (Head == NULL) {
            Head = new Node (arr[i]);
            Tail = Head;
        }
        // Exist karta hai
        else {
            Node *temp = new Node(arr[i]);
            Tail->next = temp;
            temp->prev = Tail;
            Tail = temp;
        }
    }

    // Print the Linked List
    Node *trav;
    trav = Head;

    while(trav){
        cout << trav->data << " ";
        trav = trav->next;
    }
}