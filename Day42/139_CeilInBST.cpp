// Problem: Ceil in a BST
// Link: https://www.geeksforgeeks.org/ceiling-in-a-sorted-array/
// Difficulty: Easy
// Approach: BST traversal — if root->val == key return root, if < key go right, else go left and update ceil
// Time: O(h) | Space: O(1)


/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    void solve(Node* root, int k, int&ans){
        if(!root) return;
        
        if(root->data == k){
            ans = root->data;
            return;
        }
        
        if(root->data < k){
            solve(root->right, k, ans);
        }
        else{
            ans = root->data;
            solve(root->left, k, ans);
        }
    }
  public:
    int findCeil(Node* root, int x) {
       int ans = -1;
       solve(root, x, ans);
       return ans;
        
    }
};
