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

    // Print the Linked List
    Node *temp;
    temp = Head;

    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
/*
Time Complextit :- O(n)
Space Complexity:- O(n)
*/ 