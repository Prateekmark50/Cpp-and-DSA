// GFG:- Left View of Binary Tree
// Link:- https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Method 1:- 

/*
Examples :

Input: root = [1, 2, 3, 4, 5, N, N]
           1
         /   \
        2     3
       /   \
      4     6
Output:[1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]
           1
         /   \
        2     3
             /
            4
             \
              5
Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.
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

vector<int> leftView(Node *root) {
    queue<Node *> q;
    q.push(root);
    vector<int> ans;

    while (!q.empty()) {
        int n = q.size();
        ans.push_back(q.front()->data);

        while (n--) {
            Node *temp = q.front();
            q.pop();

            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
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

    cout << "\nLeft View of Binary Tree:\n";
    vector<int> result = leftView(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}