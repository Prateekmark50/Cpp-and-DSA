// GFG:- Detect Loop in linked list
// Method 2:- Using unordered map
#include<iostream>
#include <unordered_map>
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
    Node *curr = Head;
    unordered_map<Node *,bool> visited;
    while (curr != NULL) {
        if (visited[curr] == 1) {
            return 1;
        }

        visited[curr] = 1;
        curr = curr->next;
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
    O(n)
*/ 