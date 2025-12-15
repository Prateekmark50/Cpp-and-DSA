// GFG:- Remove Duplicates from a Sorted Linked List
// Method 2
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

Node* removeDuplicates(Node* Head) {
    if (!Head || !Head->next) { // Edge Case
        return Head;
    }

    Node *prev = Head, *curr = Head->next;
    while (curr) {
        // Duplicate hai
        if (curr->data == prev->data) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        // Duplicate nahi hai
        else {
            prev = prev->next;
            curr = curr->next;
        }
    }
    
    return Head;
}

int main(){
    Node *Head;
    Head = NULL;
    
    int arr[] = {2,2,4,5};
    
    // creating linked list
    Head = createLinkedList(arr, 0, 4);

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
    Head = removeDuplicates(Head);

    // Print the Linked List After 
    temp = Head;
    cout << "After Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}