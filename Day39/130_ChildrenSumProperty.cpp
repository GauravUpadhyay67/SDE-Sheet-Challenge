// Problem: Children Sum Property in Binary Tree
// Link: https://www.geeksforgeeks.org/check-for-children-sum-property-in-a-binary-tree/
// Difficulty: Medium
// Approach: DFS — each node value = sum of children values
// Time: O(n) | Space: O(h)



/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    int isSumProperty(Node *root) {
        if(!root) return 1;
        if(!root->left && !root->right) return 1;
        
        int leftAns = isSumProperty(root->left);
        int rightAns = isSumProperty(root->right);
        
        int sum = 0;
        if(root->left) sum += root->left->data;
        if(root->right) sum += root->right->data;
        
        if(sum != root->data) return 0;
        
        return leftAns && rightAns;
        
    }
};
