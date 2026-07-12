// Problem: Find Kth Smallest Element in BST
// Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
// Difficulty: Medium
// Approach: Inorder traversal — kth element in inorder = kth smallest
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
    void inorder(TreeNode* root, int& k, int& ans){
        if(!root) return;

        inorder(root->left, k, ans);
        k--;
        if(k == 0){
            ans = root->val;
            return;
        }
        inorder(root->right, k, ans);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1;
        inorder(root, k, ans);
        return ans;
    }
};
