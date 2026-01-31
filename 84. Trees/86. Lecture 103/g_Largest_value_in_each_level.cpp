// GFG:- Largest value in each level
// Link:- https://www.geeksforgeeks.org/problems/largest-value-in-each-level/1

/*
Example 1:

Input :
        1
       / \
      2   3 

Output : 1 3
Explanation : 
There are two levels in the tree :
1. {1}, max = 1
2. {2, 3}, max = 3

Example 2:

Input :
        4
       / \
      9   2
     / \   \
    3   5   7 

Output : 4 9 7
Explanation : 
There are three levels in the tree:
1. {4}, max = 4
2. {9, 2}, max = 9
3. {3, 5, 7}, max=7
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

vector<int> largestValues(Node* root) {
    vector<int> ans;
    queue<Node *>q;
    q.push(root);

    while (!q.empty()) {
        int maxi = 0;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node *temp = q.front();
            q.pop();

            maxi = max(maxi, temp->data);
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        ans.push_back(maxi);
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

        // Left Node
        cout << "Enter the left value of " << temp->data << ": ";
        cin >> first; // Left node ki value
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
    Node *root = BinaryTree();

    cout << "\nLargest value at each level:\n";
    vector<int> result = largestValues(root);
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
}