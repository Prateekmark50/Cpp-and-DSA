// GFG:- Count Non-Leaf Nodes in Tree
// Link:- https://www.geeksforgeeks.org/problems/count-non-leaf-nodes-in-tree/1

/*
Example:

Input: 
          1
        /   \
       2     3
      / \
     4   5
Output: 2
Explanation: Nodes 1 and 2 are the only non leaf nodes.

Input: 
          8
        /   \
       3     9
      / \
     1   6
        / \
       4   7
Output: 3
Explanation: Nodes 8, 3 and 6 are the only non leaf nodes.

Input: 
          10
        /    \
      5       20
     / \     /  \
    3   7   15   25
Output: 3
Explanation: Nodes 10, 5 and 20 are the only non leaf nodes.
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

int countNonLeafNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    // Leaf Node
    if (!root->left && !root->right) {
        return 0;
    }
    
    // No Leaf
    return (1 + countNonLeafNodes(root->left) + countNonLeafNodes(root->right));
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
    // cout << "Enter the Root Node: ";
    Node *root;
    root = BinaryTree();

    cout << "\nCount of Non-Leaves Nodes in Binary Tree = " << countNonLeafNodes(root) << endl;
    return 0;
}