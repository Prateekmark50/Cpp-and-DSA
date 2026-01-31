// GFG:- Check if two Nodes are Cousins
// Link:- https://www.geeksforgeeks.org/problems/check-if-two-nodes-are-cousins/1

/*
Examples:

Input:
      1
    /   \
   2     3
a = 2, b = 3
Output: false
Explanation: Here, nodes 2 and 3 are at the same level but have same parent nodes.

Input:
       1
     /   \ 
    2     3
   /       \
  5         4 
a = 5, b = 4
Output: True
Explanation: Here, nodes 5 and 4 are at the same level and have different parent nodes. Hence, they both are cousins. 

Input:
          10
        /    \
      5       15
     / \     /  \
    3   7   12   20
a = 7, b = 12
Output: True
Explanation: Here, nodes 7 and 12 are at the same level and have different parent nodes. Hence, they both are cousins. 
*/ 

/*
class Solution {
  public:
    // Function to check if two nodes are cousins in a tree
    bool isCousins(Node* root, int x, int y) {
        int level_x = -1,level_y = -1;//level of x&y
        int parent_x = -1,parent_y = -1;//parent of x&y
        int level = 0;//keep track of level
        //level order traversal
        queue<Node*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            level += 1;
            
            for(int i=0;i<size;i++){
            Node* temp = q.front();
            q.pop();
            
            //checks if left child is x or y
            if(temp->left){
                if(temp->left->data == x){
                    parent_x = temp->data;
                    level_x = level+1;
                }
                if(temp->left->data == y){
                    parent_y = temp->data;
                    level_y = level+1;
                }
                q.push(temp->left);
            }
            
            // checks is right child is x or y
            if(temp->right){
                if(temp->right->data == x){
                    parent_x = temp->data;
                    level_x = level+1;
                }
                if(temp->right->data == y){
                    parent_y = temp->data;
                    level_y = level+1;
                }
                q.push(temp->right);
            }
            }
            
            //break early if both found
            if(level_x != -1 && level_y != -1)
            break;
        }
        return ((level_x == level_y) && (parent_x!=parent_y));
        
    }
};
*/ 