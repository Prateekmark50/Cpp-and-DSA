// GFG:- Preorder Traversal
// Link:- https://www.geeksforgeeks.org/problems/preorder-traversal/1

/*
Examples:

Input: root = [1, 4, N, 4, 2]
Output: [1, 4, 4, 2]
Explanation: The preorder traversal of the given binary tree is [1, 4, 4, 2]

Input: root = [6, 3, 2, N, 1, 2, N]
Output: [6, 3, 1, 2, 2] 
Explanation: The preorder traversal of the given binary tree is [6, 3, 1, 2, 2] 
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

void pre(Node *root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }

    // Node
    ans.push_back(root->data);

    // Left
    pre(root->left, ans);

    // Right
    pre(root->right, ans);
}

vector<int> preOrder(Node* root) {
    vector<int> ans;
    pre(root, ans);
    return ans;
}

Node *BinaryTree() {
    // int x;
    // cin >> x;

    // if (x == -1) {
    //     return NULL;
    // }
    
    // Node *temp = new Node(x);

    // // Left Side Create
    // cout << "Enter the Left Child of " << x << ": ";
    // temp->left = BinaryTree();

    // // Right Side Create
    // cout << "Enter the Right Child of " << x << ": ";
    // temp->right = BinaryTree();

    // return temp;

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

    vector<int> result = preOrder(root);

    cout << "\nPreorder Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
Time Complexity:-
    O(n), here n is node
Space Complexity:-
    O(h), here h is height
*/ 