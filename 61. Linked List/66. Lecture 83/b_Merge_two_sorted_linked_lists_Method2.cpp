// GFG:- Merge two sorted linked lists
// Method 2 :- Optimed Method
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
    Node *Head = new Node(0);
    Node* Tail = Head;
    while (Head1 && Head2) {
        if (Head1->data <= Head2->data) {
            Tail->next = Head1;
            Head1 = Head1->next;
            Tail = Tail->next;
            Tail->next = NULL;
        }
        
        else {
            Tail->next = Head2;
            Head2 = Head2->next;
            Tail = Tail->next;
            Tail->next = NULL;
        }
    }

    if (Head1) {
        Tail->next = Head1;
    }
    else {
        Tail->next = Head2;
    }
    Tail = Head;
    Head = Head->next;
    delete Tail;

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
    cout << "Before Second Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout <<endl;

    // To Merged two Sorted linked list
    Head = sortedMerge(Head1, Head2);

    // Print the Linked List After 
    temp = Head;
    cout << "Merged Sorted Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}