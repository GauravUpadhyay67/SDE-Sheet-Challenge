// Problem: LCA in BST
// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
// Difficulty: Medium
// Approach: BST property — if both p,q < root go left, if both > root go right, else root is LCA
// Time: O(h) | Space: O(1)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;

        if(root->val < p->val && root->val < q->val) return lowestCommonAncestor(root->right, p, q);

        if(root->val > p->val && root->val > q->val) return lowestCommonAncestor(root->left, p, q);

        return root;
    }
};
