// GFG:- Sort a linked list of 0s, 1s and 2s
// Method 1
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

Node* segregate(Node* head) {
    Node *curr = head;
    int count0 = 0, count1 = 0, count2 = 0;
    while (curr) {
        if (curr->data == 0) {
            count0++;
        }
        else if (curr->data == 1) {
            count1++;
        }
        else {
            count2++;
        }
        curr = curr->next;
    }

    curr = head;
    // while (curr) {
    //     if (count0 != 0) {
    //         curr->data = 0;
    //         count0--;
    //     }
    //     else if (count0 == 0 && count1 != 0) {
    //         curr->data = 1;
    //         count1--;
    //     }
    //     else {
    //         curr->data = 2;
    //         count2--;
    //     }
    //     curr = curr->next;
    // }
    while (count0--) {
        curr->data = 0;
        curr = curr->next;
    }
    while (count1--) {
        curr->data = 1;
        curr = curr->next;
    }
    while (count2--) {
        curr->data = 2;
        curr = curr->next;
    }

    return head;
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