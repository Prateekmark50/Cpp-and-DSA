// Leetcode:- Rotate List
#include<iostream>
using namespace std;

class ListNode{
    public:
        int value;
        ListNode *next;
        ListNode(int data){
            value = data;
            next = NULL;
        }
};

ListNode *createLinkedList(int arr[], int index, int size){
    // Base Case
    if(index == size){
        return NULL;
    }

    ListNode *temp;
    temp = new ListNode(arr[index]);
    temp->next = createLinkedList(arr, index+1, size);

    return temp;
}

ListNode* rotateRight(ListNode* Head, int k) {
    if (Head == NULL || Head->next == NULL) {
        return Head;
    }
    
    // Count number of nodes
    int count = 0;
    ListNode* temp = Head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    k = k % count;
    if (k == 0) {
        return Head;
    }
    count = count - k;
    ListNode *curr = Head, *prev = NULL;
    while (count--){
        prev = curr;
        curr = curr->next;
    }

    prev->next = NULL;
    ListNode* Tail = curr;
    // Second list uske last node pe leke jao
    while (Tail->next != NULL) {
        Tail = Tail->next;
    }
    Tail->next = Head;
    Head = curr;

    return Head;
    
}

int main(){
    ListNode *Head;
    Head = NULL;
    
    int arr[] = {1,2,3,4,5};
    int k = 2;
    // creating linked list
    Head = createLinkedList(arr, 0, 5);

    // Print the Linked List Before 
    ListNode *temp;
    temp = Head;
    cout << "Before Linked List:" <<endl;
    while(temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout <<endl;

    // To find middle of the linked list
    Head = rotateRight(Head, k);

    // Print the Linked List After 
    temp = Head;
    cout << "After Linked List:" <<endl;
    while(temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
}