// Problem: Postorder Traversal
// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
// Difficulty: Easy
// Approach: Recursive — Left, Right, Root
// Time: O(n) | Space: O(h)



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    void solve(TreeNode* root, vector<int>&ans){
        if(!root) return;
        
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root, ans);
        return ans;
    }
};
