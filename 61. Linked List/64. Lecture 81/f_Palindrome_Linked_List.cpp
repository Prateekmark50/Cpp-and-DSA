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

bool isPalindrome(ListNode* Head) {
    if (Head->next) {
        return true;
    }

    // Count number of nodes
    int count = 0;
    ListNode* temp = Head;
    while (temp) {
        count++;
        temp = temp->next;
    }

    count = count/2;
    ListNode* curr = Head, *prev = NULL;
    // Skip number of nodes
    while (count--) {
        prev = curr;
        curr = curr->next;
    }
    prev->next = NULL;

    // Reverse the second linked list , curr is pointing it
    ListNode* fut;
    prev = NULL;

    while (curr) {
        fut = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fut;
    }
    
    // Prev is pointing to second list
    // Head is pointing to first list 
    ListNode* Head1 = Head, *Head2 = prev;
    // Check Palindrome
    while (Head1) {
        if (Head1->value != Head2->value) {
            return false;
        }
        Head1 = Head1->next;
        Head2 = Head2->next;
    }
    return true;
}

int main(){
    ListNode *Head;
    Head = NULL;
    
    int arr[] = {1,2,2,1};
    
    // creating linked list
    Head = createLinkedList(arr, 0, 4);

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
    cout << "Linked List is Palindrome or not? : " <<isPalindrome(Head);

}
/*
Time Complexity:-
    O(N)
Space Complexity:-
    O(1)
*/