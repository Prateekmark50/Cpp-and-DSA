// GFG:- Remove Duplicates from a Sorted Linked List
// Method 1
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

Node* removeDuplicates(Node* Head) {
    vector<int> ans;
    ans.push_back(Head->data);
    Node *curr = Head->next;
    while (curr) {
        // Duplicate nahi mila
        if (ans[ans.size()-1] != curr->data) {
            ans.push_back(curr->data);
        }
        curr = curr->next;
    }

    curr = Head;
    int index = 0;
    Node *prev = NULL;
    while (index < ans.size()) {
        curr->data = ans[index];
        index++;
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    return Head;
}

int main(){
    Node *Head;
    Head = NULL;
    
    int arr[] = {2,2,4,5};
    
    // creating linked list
    Head = createLinkedList(arr, 0, 4);

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
    Head = removeDuplicates(Head);

    // Print the Linked List After 
    temp = Head;
    cout << "After Linked List:" <<endl;
    while(temp){
        cout << temp->data << " ";
        temp = temp->next;
    }
}