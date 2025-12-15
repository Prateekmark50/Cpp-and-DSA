// GFG:- Count Leaves in Binary Tree
// Link:- https://www.geeksforgeeks.org/problems/count-leaves-in-binary-tree/1

/*
Examples:

Input:
Given Tree is  
           4
         /   \
        8    10
      /     /   \
     7     5     1
    /
   3
Output: 3
Explanation: Three leaves are 3, 5 and 1.

Input:
Given Tree is
           50
         /    \
        30     70
      /   \   /   \
     20   40  60   80
                \
                65
Output: 4
Explanation: Four leaves are 20, 40, 65 and 80.

Input:
Given Tree is  
           30
         /    \
        25     35
      /   \       \
     20   28       40
          /
        27
Output: 3
Explanation: Three leaves are 20, 27 and 40.
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

void CountLeaf(Node *root, int &count) {
    if (root == NULL) {
        return;
    }
    if (!root->left && !root->right) {
        count++;
        return;
    }
    CountLeaf(root->left, count);
    CountLeaf(root->right, count);
} 

int countLeaves(Node* root) {
    int count = 0;
    CountLeaf(root, count);
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

    cout << "\nCount of Leaves Nodes in Binary Tree = " << countLeaves(root) << endl;
    return 0;
}