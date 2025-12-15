// GFG :- Delete in a Singly Linked List
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

// Delete a particular Node from Linked List
Node *deleteNode(Node *Head, int x){
    // Base Case
    if(x == 1){
        Node *temp = Head->next;
        delete Head;
        return temp;
    }
    Head->next = deleteNode(Head->next, x-1);
    return Head;
}

int main(){
    int x = 3;
    Node *Head;
    Head = NULL;

    int arr[] = {2,4,6,8,10};

    // creating linked list
    Head = createLinkedList(arr, 0, 5);

    // Delete a particular Node from Linked List
    Head = deleteNode(Head, x);
    
    // Print the Linked List
    Node *temp;
    temp = Head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}