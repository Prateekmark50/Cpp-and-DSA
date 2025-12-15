// Method 2
// uisng ans array to write all the data, and then arrange in linked list
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

ListNode *rotateRight(ListNode* Head, int k) {
    if(Head == NULL || Head->next == NULL || k == 0) {
        return Head;
    }

    ListNode* temp = Head;
    vector<int> ans;
    while (temp) {
        ans.push_back(temp->value);
        temp = temp->next;
    }

    int n = ans.size();
    k = k % n;
    if(k == 0) {
        return Head;
    }

    int pos = n - k;

    temp = Head;
    while (temp) {
        temp->value = ans[pos % n];
        temp = temp->next;
        pos++;
    }
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