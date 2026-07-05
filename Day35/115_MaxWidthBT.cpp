// Problem: Maximum Width of Binary Tree
// Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Difficulty: Medium
// Approach: BFS level order — assign indices, width = last - first + 1
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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long long>>q;
        long long maxWidth = 0;
        q.push({root, 0});

        while(!q.empty()){
            long long size = q.size();

            long long minIndex = q.front().second;
            long long leftIndex = 0, rightIndex = 0;
            for(int i=0; i<size; i++){
                TreeNode* node = q.front().first;
                long long idx = q.front().second;
                q.pop();
                long long index = idx - minIndex;

                if(i == 0) leftIndex = index;
                if(i == size-1) rightIndex = index;

                if(node->left) q.push({node->left, index*2 + 1});
                if(node->right) q.push({node->right, index*2 + 2});
            }
            maxWidth = max(maxWidth, rightIndex-leftIndex+1);
        }
        return (int)maxWidth;
    }
};
