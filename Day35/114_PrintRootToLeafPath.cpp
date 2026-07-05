// Problem: Print Root to Leaf Path in BT
// Link: https://leetcode.com/problems/binary-tree-paths/
// Difficulty: Medium
// Approach: DFS recursion — add node to path, print on leaf, backtrack
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
public:
    void getAllPath(TreeNode* root, string path, vector<string>& res){

        if(!root) return;

        if (!path.empty()) path += "->";
        path += to_string(root->val);

        if(!root->left && !root->right){
            res.push_back(path);
        }

        getAllPath(root->left, path, res);
        getAllPath(root->right, path, res);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        string s = "";
        getAllPath(root, s, res);
        return res;
    }
};
