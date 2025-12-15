// GFG:- Flattening a Linked List
// Link:- https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *bottom;
        Node(int value){
            data = value;
            next = NULL;
            bottom = NULL;
        }
};

Node *createLinkedList(int arr[], int index, int size){
    // Base Case
    if(index == size){
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = createLinkedList(arr, index+1, size);

    return temp;
}

Node* sortedMerge(Node* Head1, Node* Head2) {
    Node *Head = new Node(0);
    Node* Tail = Head;
    while (Head1 && Head2) {
        if (Head1->data <= Head2->data) {
            Tail->bottom = Head1;
            Head1 = Head1->bottom;
            Tail = Tail->bottom;
            Tail->bottom = NULL;
        }
        
        else {
            Tail->bottom = Head2;
            Head2 = Head2->bottom;
            Tail = Tail->bottom;
            Tail->bottom = NULL;
        }
    }

    if (Head1) {
        Tail->bottom = Head1;
    }

    else {
        Tail->bottom = Head2;
    }

    Tail = Head;
    Head = Head->bottom;
    delete Tail;

    return Head;
}

Node *flatten(Node *root) {
    Node *head1, *head2, *head3;
    while (root->next) {
        head1 = root;
        head2 = root->next;
        head3 = root->next->next;

        head1->next = NULL;
        head2->next = NULL;

        root = sortedMerge(head1, head2);
        root->next = head3;
    }
    return root;
}

int main(){
    /* Create a hard-coded linked list:
        5 -> 10 -> 19 -> 28
        |    |     |
        V    V     V
        7    20    22
        |          |
        V          V
        8          50
        |
        V
        30
    */

    Node* head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);
    head->bottom->bottom->bottom = new Node(30);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);
    head->next->next->bottom->bottom = new Node(50);

    head->next->next->next = new Node(28);

    // To Merged two Sorted linked list
    head = flatten(head);

    // Print the Linked List After 
    Node *temp = head;
    cout << "Flatening Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->bottom;
    }
}
/*
Time Complexity:-
    O(m * n^2)
    m is vertical(bottom)
    n is horizontal(next)
Space Complexity:-
    O(1)
*/ 