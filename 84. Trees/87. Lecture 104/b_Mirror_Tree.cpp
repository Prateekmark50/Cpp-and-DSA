// GFG:- Mirror Tree
// Link:- https://www.geeksforgeeks.org/problems/mirror-tree/1

/*
Examples:

Input: root = [1, 2, 3, N, N, 4]
Output: [1, 3, 2, N, 4]
Explanation: 
                    Mirror
           1          |           1
         /   \        |         /   \
        2     3       |        3     2
             /        |         \
            4         |          4
  Input Binary Tree   |    Inverted Binary Tree
In the inverted tree, every non-leaf node has its left and right child interchanged.

Input: root = [1, 2, 3, 4, 5]
Output: [1, 3, 2, N, N, 5, 4]
Explanation:
                    Mirror
           1          |           1
         /   \        |         /   \
        2     3       |        3     2
       /  \           |             /  \
      4    5          |            5    4
  Input Binary Tree   |    Inverted Binary Tree
In the inverted tree, every non-leaf node has its left and right child interchanged.
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

void mirror(Node* root) {
    if (root == NULL) {
        return;
    }

    Node *temp = root->right;
    root->right = root->left;
    root->left = temp;

    mirror(root->left);
    mirror(root->right);
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

    mirror(root);

    cout << "\nLevel Order Traversal After Mirroring:\n";
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        if (temp->left) {
            q.push(temp->left);
        }

        if (temp->right) {
            q.push(temp->right);
        }
    }
    return 0;
}