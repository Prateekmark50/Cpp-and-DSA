// GFG:- Reverse a sublist of a linked list
// Link:- https://www.geeksforgeeks.org/problems/reverse-a-sublist-of-a-linked-list/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab
/*
Input: a = 1, b = 8, Linked List = 1->7->5->3->9->8->10->2->2->5->NULL
Output: 2 10 8 9 3 5 7 1 2 5
Explanation: The nodes from position 1 to 8 are reversed, resulting in 2 10 8 9 3 5 7 1 2 5.
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

Node *reverseBetween(Node *Head, int a, int b) {
    // Dummy node create karo
    Node *first = new Node(0);
    first->next = Head;
    Head = first;
    int x = a, y = b;
    Node *second, *prev, *curr, *fut;

    while (--x) {
        first = first->next;
        y--;
    }

    second = first->next;
    prev = first;
    curr = first->next;

    while (y) {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
        y--;
    }

    first->next = prev;
    second->next = curr;

    // Dummy Node ko delete kar do
    first = Head;
    Head = Head->next;
    delete first;

    return Head;
}
// we can write above code like this also
/*
Node *reverseBetween(Node *Head, int a, int b) {
    // Dummy node create karo
    Node *first = new Node(0);
    first->next = Head;
    Head = first;
    int x = a, y;
    Node *second, *prev, *curr, *fut;

    x--;
    while (x) {
        first = first->next;
        x--;
    }

    second = first->next;
    prev = first;
    curr = first->next;

    y = b - a + 1;
    while (y) {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
        y--;
    }

    first->next = prev;
    second->next = curr;

    // Dummy Node ko delete kar do
    first = Head;
    Head = Head->next;
    delete first;

    return Head;
}
*/

int main(){
    Node *Head = NULL;
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int a = 1, b = 8;
    
    // creating linked list
    Head = createLinkedList(arr, 0, 10);

    // Print the Linked List Before 
    Node *temp;
    temp = Head;
    cout << "Before Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;

    // To find middle of the linked list
    Head = reverseBetween(Head, a, b);

    // Print the new Added Linked List After 
    temp = Head;
    cout << "After Reversing Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}