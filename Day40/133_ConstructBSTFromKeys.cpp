// Problem: Construct BST from Given Keys
// Link: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Difficulty: Easy
// Approach: Recursion — mid element as root, recurse left and right halves
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
    TreeNode* solve(vector<int>&nums, int l, int r){
        if(l > r) return NULL;

        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->val = nums[mid];
        root->left = solve(nums, l, mid-1);
        root->right = solve(nums, mid+1, r);

        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return solve(nums, 0, nums.size()-1);
    }
};
