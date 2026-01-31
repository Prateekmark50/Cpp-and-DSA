// GFG:- Balanced Tree Check
// Link:- https://www.geeksforgeeks.org/problems/check-for-balanced-tree/1

/*
Examples:

Input: root = [10, 20, 30, 40, 60]
           10
         /    \
        20     30
       /   \
      40   60
Output: true 
Explanation: The height difference between the left and right subtrees at all nodes is at most 1. Hence, the tree is balanced.

Input: root = [1, 2, 3, 4, N, N, N, 5]
           1
         /   \
        2     3
      /
     4
    /
   5
Output: false
Explanation: The height difference between the left and right subtrees at node 2 is 2, which exceeds 1. Hence, the tree is not balanced.
*/ 

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node{
public:
    int data;
    Node *left, *right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

int height(Node *root, bool &valid) {
    if (root == NULL) {
        return 0;
    }

    if (valid) { // this condition will help me to stop running below code when valid=0
        int L = height(root->left, valid);
        int R = height(root->right, valid);

        if (abs(L-R) > 1) {
            valid = 0;
        }

        return 1 + max(L,R);
    }
    return -1;
}

bool isBalanced(Node* root) {
    bool valid = 1;
    height(root, valid);
    return valid;
}

Node *BinaryTree() {
    int x;
    cout << "Enter the root element: ";
    cin >> x;

    int first, second;

    queue<Node *> q;
    Node *root = new Node(x);
    q.push(root);

    // Build the Binary Tree
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << "Enter the left value of " << temp->data << ": ";
        cin >> first; // Left node ki value
        // Left Node
        if (first != -1) {
            temp->left = new Node(first);
            q.push(temp->left);
        }

        // Right Node
        cout << "Enter the right value of " << temp->data << ": ";
        cin >> second;
        if (second != -1) {
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    return root;
}

int main() {
    Node *root;
    root = BinaryTree();

    bool result = isBalanced(root);

    if (result)
        cout << "\nTree is height-balanced\n";
    else
        cout << "\nTrees is NOT height-balanced\n";
    return 0;
}