// Leetcode:- Middle of the Linked List
// Method 1
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

ListNode* middleNode(ListNode* Head) {
    int count = 0;
    ListNode* temp = Head;
    
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }

    count = count/2;
    temp = Head;

    while (count--) {
        temp = temp->next;
    }

    return temp;
}

int main(){
    ListNode *Head;
    Head = NULL;
    
    int arr[] = {1,2,3,4,5};

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
    Head = middleNode(Head);

    // Print the Linked List After 
    temp = Head;
    cout << "After Linked List:" <<endl;
    while(temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
}