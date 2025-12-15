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

int main(){
    Node *Head;
    Head = NULL;

    int arr[] = {2,4,6,8,10};

    Head = createLinkedList(arr, 0, 5);

    // Delete a Node at End, we need to handle 3 things
    // 1. Linked doesn't exist
    // 2. Linked List, 1 Node hai
    // 3. Linked List, more than 1 node
    if(Head != NULL){
        // Only 1 node is present
        if(Head->next == NULL){
            // delete Head;
            // Head = NULL;
            Node *temp = Head;
            delete temp;
            Head = NULL;
        }
        // More than 1 node is present
        else{
            Node *curr = Head;
            Node *prev = NULL;

            // curr->next is not NULL
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
    }

    // Print the Linked List
    Node *temp;
    temp = Head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}