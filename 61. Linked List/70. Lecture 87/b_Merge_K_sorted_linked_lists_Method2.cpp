// GFG:- Merge K sorted linked lists
// Link:- https://www.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// Method 2:- Using merge sorting to reduce time complexity

#include<iostream>
#include<vector>
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

void mergeSort(vector<Node*>& arr, int start, int end) {
    if (start >= end) {
        return;
    }
        
    int mid = start + (end -start) / 2;
    // Left Part
    mergeSort(arr, start, mid);
    // Right Part
    mergeSort(arr, mid+1, end);

    arr[start] = sortedMerge(arr[start], arr[mid+1]);
}

Node* mergeKLists(vector<Node*>& arr) {
    mergeSort(arr, 0, arr.size()-1);
    return arr[0];
}

int main() {
    int k = 3; 
  
    vector<Node*> arr(k);

    arr[0] = new Node(1);
    arr[0]->next = new Node(3);
    arr[0]->next->next = new Node(5);
    arr[0]->next->next->next = new Node(7);

    arr[1] = new Node(2);
    arr[1]->next = new Node(4);
    arr[1]->next->next = new Node(6);
    arr[1]->next->next->next = new Node(8);

    arr[2] = new Node(0);
    arr[2]->next = new Node(9);
    arr[2]->next->next = new Node(10);
    arr[2]->next->next->next = new Node(11);
    
    Node* Head = mergeKLists(arr);

    // Print the Linked List After 
    Node *temp = Head;
    cout << "Flatening Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}
/*
Time Complexity:-
    O(n * k * log k), where n is the number of nodes in the longest list.
Space Complexity:-
    O(log k), used for recursion.
*/ 