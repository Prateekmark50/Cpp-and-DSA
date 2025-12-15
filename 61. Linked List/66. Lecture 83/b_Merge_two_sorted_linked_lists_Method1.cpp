// GFG:- Merge two sorted linked lists
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

Node* sortedMerge(Node* Head1, Node* Head2) {
    Node *curr1 = Head1, *curr2 = Head2, *Head = NULL, *Tail;
    while (curr1 || curr2) {
        if (curr1->data <= curr2->data) {
            if(Head == NULL) {
                Head = new Node(curr1->data);
                Tail = Head;
            }
            else {
                Node *temp = new Node(curr2->data);
                Tail->next = temp;
                Tail = temp;
            }
        }
        else {
            if(Head == NULL) {
                Head = new Node(curr1->data);
                Tail = Head;
            }
            else {
                Node *temp = new Node(curr2->data);
                Tail->next = temp;
                Tail = temp;
            }
        }
    }     
    
    return Head;
}

int main(){
    Node *Head1 = NULL, *Head2 = NULL, *Head = NULL;
    
    int arr1[] = {5,10,15,40};
    int arr2[] = {2,3,20};
    
    // creating linked list
    Head1 = createLinkedList(arr1, 0, 4);
    Head2 = createLinkedList(arr2, 0, 3);

    // Print the Linked List Before 
    Node *temp;
    temp = Head1;
    cout << "Before First Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;

    temp = Head2;
    cout << "Before First Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;

    // To find middle of the linked list
    Head = sortedMerge(Head1, Head2);

    // Print the Linked List After 
    temp = Head;
    cout << "After Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}