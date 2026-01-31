// GFG:- Right View of Binary Tree
// Link:- https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
// Method 2:- Using Recursion

/*
Examples :

Input: root = [1, 2, 3, N, N, 4, 5]
           1
         /   \
        2     3
            /   \
           4     5
Output: [1, 3, 5]

Input: root = [1, 2, 3, 4, N, N, N, N, 5]
           1
         /   \
        2     3
       /
      4
        \
          5
Output: [1, 3, 4, 5]
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

void RView (Node *root, int level, vector<int> &ans) {
    if (root == NULL) {
        return;
    }

    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    RView (root->right, level+1, ans);
    RView (root->left, level+1, ans);
}

vector<int> rightView(Node *root) {
    vector<int> ans;
    RView(root, 0, ans);
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

    cout << "\nRight View of Binary Tree:\n";
    vector<int> result = rightView(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}