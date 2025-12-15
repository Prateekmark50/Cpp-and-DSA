/*
Before Revrsing
_____   _______   _______   _______   _______   ________
|100|-->|1|200|-->|2|400|-->|3|300|-->|4|800|-->|5|NULL|
Head      100       200       400       300       800

After Reversing
________   _______   _______   _______   _______   _____
|1|NULL|<--|2|100|<--|3|200|<--|4|400|<--|5|300|<--|800|
   100       200       400       300       800      Head
*/
#include<iostream>
#include<vector>
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

ListNode* reverseList(ListNode* Head) {
    ListNode *curr = Head, *prev = NULL, *fut = NULL;
    while (curr) {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    Head = prev;
    return Head;
}

int main(){
    ListNode *Head;
    Head = NULL;
    
    int arr[] = {1,2,3,4,5};
    // creating linked list
    Head = createLinkedList(arr, 0, 5);

    // Print the Linked List Before Reversing
    ListNode *temp;
    temp = Head;
    cout << "Before Reversing the Linked List:" <<endl;
    while(temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
    cout <<endl;

    // Reverse the data in linked list
    Head = reverseList(Head);

    // Print the Linked List After Reversing
    temp = Head;
    cout << "After Reversing the Linked List:" <<endl;
    while(temp){
        cout << temp->value << " ";
        temp = temp->next;
    }
}