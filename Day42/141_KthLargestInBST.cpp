// Problem: Kth Largest Element in BST
// Link: https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1
// Difficulty: Medium
// Approach: Reverse Inorder Traversal (Right → Root → Left). The Kth visited node is the answer.
// Time: O(h + k) (Worst Case: O(n)) | Space: O(h)

/* Structure of a Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
    void solve(Node* root, int& k, int& ans){
        if(!root) return;

        solve(root->right, k, ans);
        k--;
        if(k == 0){
            ans = root->data;
            return;
        }
        solve(root->left, k, ans);
    }
  public:
    int kthLargest(Node *root, int k) {
        int ans = -1;
        solve(root, k, ans);
        return ans;
    }
};
