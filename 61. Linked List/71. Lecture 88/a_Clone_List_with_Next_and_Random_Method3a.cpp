// GFG:- Clone List with Next and Random
// Link:- https://www.geeksforgeeks.org/problems/clone-a-linked-list-with-next-and-random-pointer/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// Method 3(a):- 

#include<iostream>
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
    // Create the clone Linked List insert it in original LL same time
    Node *headCopy = new Node(0);
    Node *tailCopy = headCopy;
    Node *temp = head;

    while (temp) {
        tailCopy->next = new Node(temp->data);
        tailCopy = tailCopy->next;
        temp =  temp->next;
    }

    tailCopy = headCopy;
    headCopy = headCopy->next;
    delete tailCopy;

    // Insert the Clone Linked List into Original Linked List
    Node *curr1 = head, *curr2 = headCopy;
    Node *front1, *front2;
    while (curr1) {
        front1 = curr1->next;
        front2 = curr2->next;
        curr1->next = curr2;
        curr2->next = front1;
        curr1 = front1;
        curr2 = front2;
    }

    // Assign the random pointer to the clone LL
    curr1 = head;
    while (curr1) {
        curr2 = curr1->next;
        if (curr1->random) {
            curr2->random = curr1->random->next;
        }
        curr1 = curr2->next;
    }
    
    // Disconnect the LL
    curr1 = head;
    while (curr1->next) {
        front1 = curr1->next;
        curr1->next = front1->next;
        curr1 = front1;
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
    O(1)
*/ 