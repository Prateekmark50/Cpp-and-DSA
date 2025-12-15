// GFG:- Size of Binary Tree
// Link:- http://geeksforgeeks.org/problems/size-of-binary-tree/1
// Method 1:- 

/*
Examples:

Input:      
       1
     /  \
    2    3
Output: 3
Explanation: There are three nodes in given binary tree.

Input:
      10
     /  \
   5     9
   \    / \
    1 3   6
Output: 6
Explanation: There are six nodes in given binary tree.

Input:
      1
Output: 1
Explanation: There is one nodes in given binary tree.
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

void Total(Node *node, int &count) {
    if (node == NULL) {
        return;
    }

    count++;
    Total(node->left, count);
    Total(node->right, count);
}

int getSize(Node* node) {
    int count = 0;
    Total(node, count);
    return count;
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

    cout << "\nTotal Nodes in Tree = " << getSize(root) << endl;
    return 0;
}