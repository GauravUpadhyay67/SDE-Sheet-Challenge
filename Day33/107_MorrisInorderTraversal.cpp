// Problem: Morris Inorder Traversal
// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Difficulty: Hard
// Approach: Morris — thread right pointer to inorder successor, O(1) space
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* currNode = root;

        while(currNode){
            if(!currNode->left){
                ans.push_back(currNode->val);
                currNode = currNode->right;
            }
            else{
                TreeNode* tempNode = currNode->left;
                while(tempNode->right && tempNode->right != currNode){
                    tempNode = tempNode->right;
                }

                if(tempNode->right){
                    tempNode->right = NULL;
                    ans.push_back(currNode->val);
                    currNode = currNode->right;
                }
                else{
                    tempNode->right = currNode;
                    currNode = currNode->left; 
                }
            }
        }
        return ans;
    }
};
