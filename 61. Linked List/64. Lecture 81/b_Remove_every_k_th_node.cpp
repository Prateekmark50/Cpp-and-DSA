// GFG:- Remove every k'th node
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

Node* deleteK(Node* Head, int k) {
    if (k == 1) { // Edge Case
        return NULL;
    }
    Node* curr = Head, *prev = NULL;
    int count = 1;
    while (curr) {
        if (k == count) {
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
            count = 1;
        }
        else {
            prev = curr;
            curr = curr->next;
            count++;
        }
    }
    return Head;
}

int main(){
    Node *Head;
    Head = NULL;
    
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int k = 3;
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
    Head = deleteK(Head, k);

    // Print the Linked List After 
    temp = Head;
    cout << "After Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}