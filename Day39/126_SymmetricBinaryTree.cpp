// Problem: Symmetric Binary Tree
// Link: https://leetcode.com/problems/symmetric-tree/
// Difficulty: Medium
// Approach: Recursion — check if left mirror of right at each level
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
    bool solve(TreeNode* leftNode, TreeNode* rightNode){
        if((!leftNode && rightNode) || (leftNode && !rightNode)) return false;
        if(!leftNode && !rightNode) return true;
        if(leftNode->val != rightNode->val) return false;

        bool leftAns = solve(leftNode->left, rightNode->right);
        bool rightAns = solve(leftNode->right, rightNode->left);

        return leftAns && rightAns;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return solve(root->left, root->right);
    }
};
