// GFG:- Linked List Group Reverse
// Link:- https://www.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1?
/*
Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5
Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.
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

Node *reverseKGroup(Node *Head, int k) {
    // Dummy node create karo
    Node *First = new Node(0);
    First->next = Head;
    Head = First;
    int x;
    Node * Second, *prev, *curr, *fut;

    while (First->next) {
        x = k;
        Second = First->next;
        prev = First;
        curr = First->next;
        
        while (x && curr) {
            fut = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fut;
            x--;
        }
        First->next = prev;
        Second->next = curr;
        First = Second;
    }

    // Dummy Node ko delete kar do
    First = Head;
    Head = Head->next;
    delete First;

    return Head;
}

int main(){
    Node *Head = NULL;
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 4;
    
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
    Head = reverseKGroup(Head, k);

    // Print the new Added Linked List After 
    temp = Head;
    cout << "After Reversing Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}