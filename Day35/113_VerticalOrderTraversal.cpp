// Problem: Vertical Order Traversal
// Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Difficulty: Medium
// Approach: BFS + map{col → map{row → multiset}} — sort by col, row, val
// Time: O(n log n) | Space: O(n)


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;

        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int, int>>> q;

        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int col = q.front().second.first;
            int row = q.front().second.second;
            q.pop();
            mp[col][row].insert(node->val);

            if (node->left)
                q.push({node->left, {col - 1, row + 1}});
            if (node->right)
                q.push({node->right, {col + 1, row + 1}});
        }

        for(auto& [ff, fs] : mp){
            vector<int>temp;
            for(auto& [sf, ss] : fs){
                temp.insert(temp.end(), ss.begin(), ss.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
