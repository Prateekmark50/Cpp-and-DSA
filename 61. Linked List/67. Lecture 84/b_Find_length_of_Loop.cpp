// GFG:- Find length of Loop
// Method :- 
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

int lengthOfLoop(Node *Head) {
    Node *slow = Head, *fast = Head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }
    if (fast == NULL && fast->next == NULL) {
        return 0;
    }

    int count = 1;
    slow = fast->next;

    while (slow != fast) {
        count++;
        slow = slow->next;
    }
    
    return count;
}

int main(){
    
    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    Node* Head = new Node(1);
    Head->next = new Node(3);
    Head->next->next = new Node(4);
  
	// Create a loop
    Head->next->next->next = Head->next;

    cout << lengthOfLoop(Head);
}
/*
Time Complexity:-
    O(n)
Space Complexity:-
    O(1)
*/ 