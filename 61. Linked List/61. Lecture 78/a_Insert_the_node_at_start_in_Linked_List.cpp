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

int main(){
    // // Normal way 
    // Node A1(4);

    // // But we want dynamically
    // Node *Head;
    // Head = new Node(4);
    
    // cout << Head->data << endl;
    // cout << Head->next << endl;

    int arr[] = {2,4,6,8,10};
    Node *Head;
    Head = NULL;

    // Insert the node at beginning

    for(int i = 0; i < 5; i++){
        // Linked List doesn't exist
        if(Head == NULL){
            Head = new Node(arr[i]);
        }
        // Linked List exists karti hai
        else{
            Node *temp;
            temp = new Node(arr[i]);
            temp->next = Head;
            Head = temp;
        }
    }

    // Print the value
    Node *temp = Head;
    while(temp != NULL){ // Here we can write simply temp also 
        cout << temp-> data << " ";
        temp = temp->next;
    }
}