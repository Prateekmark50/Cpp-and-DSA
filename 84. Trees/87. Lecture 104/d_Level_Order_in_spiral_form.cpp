// GFG:- Level Order in spiral form
// Link:- https://www.geeksforgeeks.org/problems/level-order-traversal-in-spiral-form/1

/*
Examples:

Input: root = [1, 3, 2]
           1
         /   \
        3     2
Output: [1, 3, 2]
Explanation: Start with root (1), print level 0 (right to left), then level 1 (left to right).

Input: root = [10, 20, 30, 40, 60]
           10
         /    \
        20     30
       /   \
      40   60
Output: [10, 20, 30, 60, 40]
Explanation: Start with root (10), print level 0 (right to left), level 1 (left to right), and continue alternating.
*/ 

#include <iostream>
#include <stack>
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

vector<int> findSpiral(Node* root) {
    stack<Node *> s1; // store karega RIGHT to LEFT
    stack<Node *> s2; // store karega LEFT to RIGHT
    s1.push(root);

    vector<int> ans;

    while (!s1.empty() || !s2.empty()) {
        if (!s1.empty()) {
            while (!s1.empty()) {
                Node *temp = s1.top();
                s1.pop();
                ans.push_back(temp->data);
                if (temp->right != NULL) {
                    s2.push(temp->right);
                }
                if (temp->left != NULL) {
                    s2.push(temp->left);
                }
            }
        }
        else {
            while (!s2.empty()) {
                Node *temp = s2.top();
                s2.pop();
                ans.push_back(temp->data);
                if (temp->left != NULL) {
                    s1.push(temp->left);
                }
                if (temp->right != NULL) {
                    s1.push(temp->right);
                }
            }
        }
    }
    return ans;
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

    cout << "\nLevel Order Traversal in spiral form:\n";
    vector<int> result = findSpiral(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}