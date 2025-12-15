// GFG:- Intersection in Y Shaped Lists
// Method 1:-
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

Node* intersectPoint(Node* head1, Node* head2) {
    Node *curr1 = head1;
    
    while (curr1->next != NULL) {
        curr1 = curr1->next;
    }
    curr1->next = head1;

    Node *slow = head2, *fast = head2;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }
    // if (fast == NULL && fast->next == NULL) {
    //     return;
    // }

    slow = head2;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main(){
    
    // creation of first list: 10 -> 15 -> 30
  	Node *head1 = new Node(10);
    head1->next = new Node(15);
    head1->next->next = new Node(30);

    // creation of second list: 3 -> 6 -> 9 -> 15 -> 30
  	Node *head2 = new Node(3);  
  	head2->next = new Node(6);
    head2->next->next = new Node(9);
  
  	// 15 is the intersection point
    head2->next->next->next = head1->next;

    Node *intersectionPoint = intersectPoint(head1, head2);

    if (intersectionPoint == nullptr)
        cout << "-1";
    else
        cout << intersectionPoint->data << endl;
}