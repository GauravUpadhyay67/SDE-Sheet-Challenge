// Problem: Check for Balanced Binary Tree
// Link: https://leetcode.com/problems/balanced-binary-tree/
// Difficulty: Medium
// Approach: DFS — return -1 if unbalanced, else return height
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
    int solve(TreeNode* root, bool &ans){
        if(!root) return 0;

        int l = solve(root->left, ans);
        int r = solve(root->right, ans);

        if(abs(l-r) > 1 || !ans){
            ans = false;
            return 0;
        }

        return 1 + max(l, r);
    }
public:
    bool isBalanced(TreeNode* root) {
        bool ans = true;
        solve(root, ans);
        return ans;
    }
};
