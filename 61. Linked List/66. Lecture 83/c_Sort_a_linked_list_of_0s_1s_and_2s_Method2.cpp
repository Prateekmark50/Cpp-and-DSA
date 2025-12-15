// GFG:- Sort a linked list of 0s, 1s and 2s
// Method 2:- Optimed Method
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

Node* segregate(Node* Head) {
    Node *curr = Head;
    Node *Head0 = new Node(0), *Tail0 = Head0;
    Node *Head1 = new Node(0), *Tail1 = Head1;
    Node *Head2 = new Node(0), *Tail2 = Head2;

    while (curr) {
        if (curr->data == 0) {
            Tail0->next = curr;
            Tail0 = Tail0->next;
        }
        else if (curr->data == 1) {
            Tail1->next = curr;
            Tail1 = Tail1->next;
        }
        else {
            Tail2->next = curr;
            Tail2 = Tail2->next;
        }
        curr = curr->next;
    }

    // Combine the three lists
    if (Head1->next) {
        Tail0->next = Head1->next;
    }
    else {
        Tail0->next = Head2->next;
    }

    Tail1->next = Head2->next;
    Tail2->next = NULL;
    
    // Update the Head
    Head = Head0->next;
    return Head;

    // // To combine the linked list we can also write the below code
    // // connect 2 to 1 and then 1 to 0
    // Tail2->next = NULL;
    // Tail1->next = Head2->next;
    // Tail0->next = Head1->next;
}

int main(){
    Node *Head;
    Head = NULL;
    
    int arr[] = {1,2,2,1,2,0,2,2};
    
    // creating linked list
    Head = createLinkedList(arr, 0, 8);

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
    Head = segregate(Head);

    // Print the Linked List After 
    temp = Head;
    cout << "After Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}