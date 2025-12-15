// GFG:- Add Number Linked Lists
// Link:- https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1?
// Method
/*
Input: head1 = 4 -> 5, head2 = 3 -> 4 -> 5
Output:  3 9 0
Explanation: Given numbers are 45 and 345. There sum is 390.
*/

#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
        Node(int value){
            data = value;
            next = NULL;
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

// Reverse the Linked List
Node *reverseLinkedList(Node *curr, Node *prev) {
    if (curr == NULL) {
        return prev;
    }
    Node *fut = curr->next;
    curr->next = prev;
    return reverseLinkedList(fut, curr);
}

// Function to add two numbers represented by Linked List
Node* addTwoLists(Node* Head1, Node* Head2) {
    Node *first = Head1, *second = Head2;
    first = reverseLinkedList(first, NULL);
    second = reverseLinkedList(second, NULL);

    Node *curr1 = first, *curr2 = second;
    Node *Head = new Node(0);
    int carry = 0;
    Node *Tail = Head;

    // Addition
    while (curr1 && curr2) {
        int sum = curr1->data + curr2->data + carry;
        Tail->next = new Node (sum % 10);
        Tail = Tail->next;
        curr1 = curr1->next;
        curr2 = curr2->next;
        carry = sum / 10;
    }

    // Sum add karna padega
    while (curr1) {
        int sum = curr1->data + carry;
        Tail->next = new Node (sum % 10);
        Tail = Tail->next;
        curr1 = curr1->next;
        carry = sum / 10;
    }
    // Curr2 exist toh nahi karta
    while (curr2) {
        int sum = curr2->data + carry;
        Tail->next = new Node (sum % 10);
        Tail = Tail->next;
        curr2 = curr2->next;
        carry = sum / 10;
    }

    // Carry exist karti hai to
    while (carry) {
        Tail->next = new Node(carry % 10);
        Tail = Tail->next;
        carry = carry / 10;
    }

    // Dummy node bhi present hai
    Head= reverseLinkedList(Head->next, NULL);
    return Head;
}

int main(){
    Node *Head1 = NULL, *Head2 = NULL, *Head = NULL;
    
    int arr1[] = {5,10,15,40};
    int arr2[] = {2,3,20};
    
    // creating linked list
    Head1 = createLinkedList(arr1, 0, 4);
    Head2 = createLinkedList(arr2, 0, 3);

    // Print the Linked List Before 
    Node *temp;
    temp = Head1;
    cout << "First Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;

    temp = Head2;
    cout << "Second Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;

    // To find middle of the linked list
    Head = addTwoLists(Head1, Head2);

    // Print the new Added Linked List After 
    temp = Head;
    cout << "Add both the Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}