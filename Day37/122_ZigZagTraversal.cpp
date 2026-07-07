// Problem: Binary Tree Zigzag Level Order Traversal
// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Difficulty: Medium
// Approach: BFS using a queue and alternate the traversal direction at each level.
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);
        bool flag = true;

        while(!q.empty()){
            int n = q.size();
            vector<int>lvl(n);

            for(int i=0; i<n; i++){
                TreeNode* node = q.front();
                q.pop();

                if(flag) lvl[i] = node->val;
                else lvl[n-i-1] = node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            ans.push_back(lvl);
            flag = !flag;
        }
        return ans;
    }
};
