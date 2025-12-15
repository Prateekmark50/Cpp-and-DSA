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
    Node *curr1 = head1, *curr2 = head2;
    int count1 = 0, count2 = 0;
    // count the nodes
    while (curr1 != NULL) {
        count1++;
        curr1 = curr1->next;
    }
    while (curr2) {
        count2++;
        curr2 = curr2->next;
    }
        
    // again point curr to their heads
    curr1 = head1, curr2 = head2;
    // point the curr at same level
    while (count1 > count2) {
        count1--;
        curr1 = curr1->next;
    }
    while (count1 < count2) {
        count2--;
        curr2 = curr2->next;
    }
        
    while (curr1 != curr2) {
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
        
    return curr1;
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
