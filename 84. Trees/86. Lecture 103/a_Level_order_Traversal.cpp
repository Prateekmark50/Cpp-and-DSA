// GFG:- Level order traversal
// Link:- https://www.geeksforgeeks.org/problems/level-order-traversal/1

/*
Examples:

Input: root = [1, 2, 3]
Output: [[1], [2, 3]]
Explanation: We start with the root node 1, so the first level of the traversal is [1]. 
Then we move to its children 2 and 3, which form the next level, giving the final output [[1], [2, 3]].

Input: root = [10, 20, 30, 40, 50]
Output: [[10], [20, 30], [40, 50]]
Explanation: We begin with the root node 10, which forms the first level as [10]. 
Its children 20 and 30 make up the second level, and their children 40 and 50 form the third level, resulting in [[10], [20, 30], [40, 50]].
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

vector<vector<int>> levelOrder(Node *root) {
    vector<vector<int>> ans;

    queue<Node *> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; i++) {
            Node *temp = q.front();
            q.pop();

            level.push_back(temp->data);
            if (temp->left != NULL) {
                q.push(temp->left);
            }
            if (temp->right != NULL) {
                q.push(temp->right);
            }
        }
        ans.push_back(level);
    }
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

    vector<vector<int>> result = levelOrder(root);

    cout << "\nLevel Order Traversal: ";
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        
    }
    cout << endl;
    return 0;
}