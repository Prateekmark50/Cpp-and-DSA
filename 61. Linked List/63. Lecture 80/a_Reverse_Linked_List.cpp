// Leetcode:- Reverse the Linked List
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
    vector<int> ans;
    ListNode *temp = Head;

    while (temp != NULL) {
        ans.push_back(temp->value);
        temp = temp->next;
    }

    int i = ans.size()-1;
    temp = Head;

    while (temp) {
        temp->value = ans[i];
        i--;
        temp = temp->next;
    }
    return Head;
}

int main(){
    ListNode *Head;
    Head = NULL;
    
    int arr[] = {1,2,3,4,5};;
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