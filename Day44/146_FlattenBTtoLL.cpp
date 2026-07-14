// Problem: Flatten Binary Tree to Linked List
// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Difficulty: Medium
// Approach: Iterative Preorder Traversal using Stack — process nodes in Root → Left → Right order and relink pointers in-place
// Time: O(n) | Space: O(n)



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
            TreeNode* node = st.top();
            st.pop();

            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);

            if(!st.empty()) node->right = st.top();
            node->left = NULL;
        }
    }
};
