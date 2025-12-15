// GFG:- Detect Loop in linked list
// Method 3:- Using two node fast and slaow
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

bool detectLoop(Node* Head) {
    Node *slow = Head, *fast = Head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}

int main(){
    
    // Create a hard-coded linked list:
    // 1 -> 3-> 4
    Node* Head = new Node(1);
    Head->next = new Node(3);
    Head->next->next = new Node(4);
  
	// Create a loop
    Head->next->next->next = Head->next;

    if (detectLoop(Head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
/*
Time Complexity:-
    O(n)
Space Complexity:-
    O(1)
*/ 