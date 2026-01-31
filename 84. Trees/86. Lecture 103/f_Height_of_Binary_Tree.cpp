// GFG:- Height of Binary Tree
// Link:- https://www.geeksforgeeks.org/problems/height-of-binary-tree/1

/*
Examples:

Input: root = [12, 8, 18, 5, 11]
     12
    /   \
   8    18
  /  \
 5   11
Output: 2
Explanation: One of the longest path from the root(node 12) goes through node 8 to node 5, which has 2 edges.

Input: root = [1, 2, 3, 4, N, 10, 5, N, N, N, N, 6, 7]
      1
    /   \
  2      3
 /      /  \
4      10   5
           /  \
          6    7
Output: 3
Explanation: The longest path from the root(node 1) to a leaf node 6 with 3 edges.
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

int height(Node* root) {
    if (root == NULL) {
        return -1; // here we have to return edges thats why I return -1, else if we need to return nodes we use return0
    }

    return 1 + max(height(root->left), height(root->right));
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

    cout << "\nHeight of Binary Tree = " << height(root) << endl;
    return 0;
}