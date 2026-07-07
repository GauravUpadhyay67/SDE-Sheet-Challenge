// Problem: Same Tree
// Link: https://leetcode.com/problems/same-tree/
// Difficulty: Easy
// Approach: Recursively compare node values and both left & right subtrees.
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
    bool solve(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        if((!p && q) || (p && !q) || (p->val != q->val)) return false;

        bool op1 = solve(p->left, q->left);
        bool op2 = solve(p->right, q->right);

        return op1 && op2;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p, q);
    }
};
