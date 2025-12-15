// GFG:- Detect Loop in linked list
// Method 1:- Using vector 
#include<iostream>
#include<vector>
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

bool check(vector<Node *> visited, Node *curr) {
    for (int i = 0; i < visited.size(); i++) {
        if (visited[i] == curr) {
            return 1;
        }
    }
    return 0;
}

bool detectLoop(Node* Head) {
    Node *curr = Head;
    vector<Node *> visited;
    while (curr != NULL) {
        if (check(visited,curr)) {
            return 1;
        }

        visited.push_back(curr);
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
    O(n^2)
Space Complexity:-
    O(n)
*/ 