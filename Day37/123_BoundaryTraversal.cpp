// Problem: Boundary Traversal of Binary Tree
// Link: https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
// Difficulty: Medium
// Approach: Traverse left boundary, then all leaf nodes, then right boundary in reverse.
// Time: O(n) | Space: O(n)



/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void leftTraversal(Node* root, vector<int>&ans){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        ans.push_back(root->data);
        if(root->left) leftTraversal(root->left, ans);
        else leftTraversal(root->right, ans);
    }
    
    void leafTraversal(Node* root, vector<int>&ans){
        if(!root) return;
        
        if(!root->left && !root->right){
            ans.push_back(root->data);
        }
        leafTraversal(root->left, ans);
        leafTraversal(root->right, ans);
    }
    
    void rightTraversal(Node* root, vector<int>&right){
        if(!root) return;
        if(!root->left && !root->right) return;
        
        
        if(root->right) rightTraversal(root->right, right);
        else rightTraversal(root->left, right);
        right.push_back(root->data);
    }
  
    vector<int> boundaryTraversal(Node *root) {
        
        vector<int> ans;
        if (!root) return ans;

        if (!(!root->left && !root->right)) ans.push_back(root->data);

        leftTraversal(root->left, ans);
        leafTraversal(root, ans);

        vector<int> right;
        rightTraversal(root->right, right);
        ans.insert(ans.end(), right.begin(), right.end());

        return ans;
    }
};
