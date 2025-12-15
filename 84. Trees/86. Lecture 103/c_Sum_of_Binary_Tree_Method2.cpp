// GFG:- Sum of Binary Tree
// Link:- https://www.geeksforgeeks.org/problems/sum-of-binary-tree/1
// Method 2:- 

/*
Examples:

Input: root = [10, 20, 30, 40, 60, N, N]
           10
         /   \
        20    30
      /    \
    40     60
Output: 160
Explanation: The sum of all the nodes is 10 + 20 + 30 + 40 + 60.

Input: root = [1, 3, 2]
      1
    /   \
   3     2
Output: 6
Explanation: The sum of all the nodes is 1 + 2 + 3 = 6.

Input: root = [1, 2, N, 4, N]
           1
         /     
        2    
      /   
    4     
Output: 7
Explanation: The sum of all the nodes is 1 + 2 + 4 = 7.
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

int sumBT(Node* root) {
    if(root == NULL) {
        return 0;
    }
    return (root->data + sumBT(root->left) + sumBT(root->right));
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

    cout << "\nSum of Nodes in Binary Tree = " << sumBT(root) << endl;
    return 0;
}