/*
Make Binary Tree in different way. And then print the Pre-Order,In-Order, Post-Order Traversal
*/
#include <iostream>
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

void PreOrder(Node *root) {
    if (root == NULL) {
        return;
    }

    // Node
    cout << root->data << " ";

    // Left
    PreOrder(root->left);

    // Right
    PreOrder(root->right);
}

void InOrder(Node *root) {
    if (root == NULL) {
        return;
    }

    // Left
    InOrder(root->left);

    // Node
    cout << root->data << " ";

    // Right
    InOrder(root->right);
}

void PostOrder(Node *root) {
    if (root == NULL) {
        return;
    }

    // Left
    PostOrder(root->left);
    
    // Right
    PostOrder(root->right);

    // Node
    cout << root->data << " ";
}

Node *BinaryTree() {
    int x;
    cin >> x;

    if (x == -1) {
        return NULL;
    }
    
    Node *temp = new Node(x);

    // Left Side Create
    cout << "Enter the Left Child of " << x << ": ";
    temp->left = BinaryTree();

    // Right Side Create
    cout << "Enter the Right Child of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

int main() {
    cout << "Enter the Root Node: ";
    Node *root;
    root = BinaryTree();

    // Tree Creation Code
    // PreOrder Print
    cout << "Pre-Order Traversal: ";
    PreOrder(root);

    // InOrder ko Print
    cout << "\nIn-Order Traversal: ";
    InOrder(root);

    // PostOrder ko Print
    cout << "\nPost-Order Traversal: ";
    PostOrder(root);
}