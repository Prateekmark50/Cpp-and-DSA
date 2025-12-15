// GFG:- Remove loop in Linked List
// Method 2:-
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

void removeLoop(Node *Head) {
    Node *slow = Head, *fast = Head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }
    if (fast == NULL && fast->next == NULL) {
        return ;
    }

    slow = Head;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    while (slow->next != fast) {
        slow = slow->next;
    }
    slow->next = NULL;
}

int main(){
    
    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    Node* Head = new Node(1);
    Head->next = new Node(3);
    Head->next->next = new Node(4);
  
	// Create a loop
    Head->next->next->next = Head->next;

    removeLoop(Head);

    Node *temp = Head;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
