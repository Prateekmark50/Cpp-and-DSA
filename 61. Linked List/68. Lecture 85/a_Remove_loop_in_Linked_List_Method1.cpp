// GFG:- Remove loop in Linked List
// Method 1:- Using unordered map
#include<iostream>
#include<unordered_map>
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
    Node *curr = Head;
    unordered_map<Node *, bool> visited;

    while (curr != NULL && curr->next != NULL) {
        if (visited[curr->next] == 1) {
            curr->next = NULL;
            break;
        }
        visited[curr] = 1;
        curr = curr->next;
    }
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
