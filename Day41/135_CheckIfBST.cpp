// Problem: Check if a Tree is a BST or not
// Link: https://leetcode.com/problems/validate-binary-search-tree/
// Difficulty: Medium
// Approach: Recursion with min/max bounds — each node must be in valid range
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
public:
    bool solve(TreeNode* root, long long  low, long long up){
        if(!root) return true;
        if(root->val >= up || root->val <= low) return false;

        bool leftAns = solve(root->left, low, root->val);
        bool rightAns = solve(root->right, root->val, up);

        return leftAns && rightAns;
    }

    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
