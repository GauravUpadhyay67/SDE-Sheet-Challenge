// Problem: Floor in a BST
// Link: https://www.geeksforgeeks.org/floor-in-binary-search-tree-bst/
// Difficulty: Easy
// Approach: BST traversal — if root->val == key return root, if > key go left, else go right and update floor
// Time: O(h) | Space: O(1)


/*
Definition for Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
    void solve(Node* root, int k, int&ans){
        if(!root) return;
        
        if(root->data == k){
            ans = root->data;
            return;
        }
        
        if(root->data < k){
            ans = root->data;
            solve(root->right, k, ans);
        }
        else{
            solve(root->left, k, ans);
        }
    }
  public:
    int findMaxFork(Node* root, int k) {
       int ans = -1;
       solve(root, k, ans);
       return ans;
    }
};
