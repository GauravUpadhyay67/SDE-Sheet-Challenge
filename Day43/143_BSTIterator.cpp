// Problem: BST Iterator
// Link: https://leetcode.com/problems/binary-search-tree-iterator/
// Difficulty: Medium
// Approach: Stack — Store the leftmost path. next() pops the top node and pushes the leftmost path of its right subtree.
// Time: Constructor: O(h), next(): O(1) amortized, hasNext(): O(1)
// Space: O(h)

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator {
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        if(node->right)
            pushAllLeft(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
