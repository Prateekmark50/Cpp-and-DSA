// GFG:- Identical Trees
// Link:- https://www.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

/*
Examples:

Input: r1 = [1, 2, 3, 4], r2 = [1, 2, 3, 4]
           1                     1
         /   \                 /   \
        2     3               2     3
      /                      /
     4                      4
Output: true
Explanation: Trees are identical.

Input: r1 = [1, 2, 3, 4], r2 = [1, 2, 3, N, N, 4]
           1                     1
         /   \                 /   \
        2     3               2     3
      /                            /
     4                            4
Output: false
Explanation: Trees are not identical.
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

bool isIdentical(Node* r1, Node* r2) {
    // check r1 and r2 are both NULL
    if (!r1 && !r2) {
        return 1;
    }

    // r1 is NULL and r2 not NULL or r1 not NULL and r2 is NULL
    if ((!r1 && r2) || (r1 && !r2)) {
        return 0;
    }

    if (r1->data != r2->data) {
        return 0;
    }

    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
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
    cout << "\nBuild First Tree:\n";
    Node* root1 = BinaryTree();

    cout << "\nBuild Second Tree:\n";
    Node* root2 = BinaryTree();

    bool result = isIdentical(root1, root2);

    if (result)
        cout << "\nBoth trees are IDENTICAL\n";
    else
        cout << "\nTrees are NOT identical\n";
    return 0;
}