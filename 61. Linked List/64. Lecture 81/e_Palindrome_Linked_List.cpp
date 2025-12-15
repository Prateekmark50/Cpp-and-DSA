// Leetcode:- Palindrome Linked List
// Method1:- Using array which take more space thats why method2 is best
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

bool isPalindrome(ListNode* Head) {
    ListNode* temp = Head;
    vector<int> ans;
    while (temp) {
        ans.push_back(temp->value);
        temp = temp->next;
    }
    int start = 0, end = ans.size()-1;
    while (start < end) {
        if (ans[start] != ans[end]) {
            return false;
        }
        start++;
        end--;
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
    O(N)
*/