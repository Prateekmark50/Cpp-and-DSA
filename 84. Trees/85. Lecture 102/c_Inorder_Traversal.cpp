// GFG:- Inorder Traversal
// Link:- https://www.geeksforgeeks.org/problems/inorder-traversal/1

/*
Examples:

Input: root = [1, 2, 3, 4, 5]        
Output: [4, 2, 5, 1, 3]
Explanation: The inorder traversal of the given binary tree is [4, 2, 5, 1, 3].

Input: root = [8, 1, 5, N, 7, 10, 6, N, 10, 6]
Output: [1, 7, 10, 8, 6, 10, 5, 6]
Explanation: The inorder traversal of the given binary tree is [1, 7, 10, 8, 6, 10, 5, 6].
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

void in(Node *root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }

    // Left
    in(root->left, ans);

    // Node
    ans.push_back(root->data);

    // Right
    in(root->right, ans);
}

vector<int> inOrder(Node* root) {
    vector<int> ans;
    in(root, ans);
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

    vector<int> result = inOrder(root);

    cout << "\nInorder Traversal: ";
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