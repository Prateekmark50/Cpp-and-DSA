// GFG:- Clone List with Next and Random
// Link:- https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// Method 2:- Using unordered map

#include<iostream>
#include <unordered_map>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node *random;
        Node(int value){
            data = value;
            next = NULL;
            random = NULL;
        }
};

Node* cloneLinkedList(Node* head) {
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;
        
    // Clone created without random pointer
    while (temp) {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
        
    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    tailCopy = headCopy;
    temp = head;
        
    unordered_map<Node*, Node*> m;
    // Fill the value inside map
    while (temp) {
        m[temp] = tailCopy;
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
        
    // Assign random pointer to the clone linked list
    temp = head;
    tailCopy = headCopy;

    while (temp) {
        tailCopy->random = m[temp->random];
        tailCopy = tailCopy->next;
        temp = temp->next;
    }
        
    return headCopy;
}

int main(){
    // Creating a linked list with random pointer
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next->next;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next;

    // Print the original list
    Node *temp = head;
    cout << "Original linked list:" <<endl;
    while (temp) {
        cout << temp->data << "(";
        if (temp->random) {
            cout << temp->random->data << ")";
        }
        else {
            cout << "NULL" << ")";
        }

        if (temp->next) {
            cout << "->";
        }

        temp = temp->next;
    }
    cout << endl;

    // To Merged two Sorted linked list
    head = cloneLinkedList(head);

    // Print the Linked List After 
    temp = head;
    cout << "Cloned linked list:" <<endl;
    while (temp) {
        cout << temp->data << "(";
        if (temp->random) {
            cout << temp->random->data << ")";
        }
        else {
            cout << "NULL" << ")";
        }

        if (temp->next) {
            cout << "->";
        }

        temp = temp->next;
    }
}
/*
Time Complexity:-
    O(n)
Space Complexity:-
    O(n), because of using map
*/ 