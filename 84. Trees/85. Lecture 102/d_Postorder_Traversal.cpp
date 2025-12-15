// GFG:- Postorder Traversal
// Link:- https://www.geeksforgeeks.org/problems/postorder-traversal/1

/*
Examples:

Input: root = [19, 10, 8, 11, 13]
Output: [11, 13, 10, 8, 19]
Explanation: The postorder traversal of the given binary tree is [11, 13, 10, 8, 19].

Input: root = [11, 15, N, 7]
Output: [7, 15, 11]
Explanation: The postorder traversal of the given binary tree is [7, 15, 11].
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

void post(Node *root, vector<int> &ans) {
    if (root == NULL) {
        return;
    }

    // Left
    post(root->left, ans);

    // Right
    post(root->right, ans);
    
    // Node
    ans.push_back(root->data);
}

vector<int> PostOrder(Node* root) {
    vector<int> ans;
    post(root, ans);
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

    vector<int> result = PostOrder(root);

    cout << "\nPostorder Traversal: ";
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