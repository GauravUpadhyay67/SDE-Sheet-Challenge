// Problem: Flatten Binary Tree to Linked List
// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Difficulty: Medium
// Approach: Morris traversal — thread right pointer, flatten in place
// Time: O(n) | Space: O(1)


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
    void flatten(TreeNode* root) {
        if(!root) return;
        stack<TreeNode*>st;
        st.push(root);

        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();

            if(curr->right) st.push(curr->right);
            if(curr->left) st.push(curr->left);

            if(!st.empty()) curr->right = st.top();
            curr->left = NULL;
        }
    }
};
