// Problem: Check for Symmetrical BTs
// Link: https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/
// Difficulty: Medium
// Approach: Recursion — compare left subtree mirror of right subtree
// Time: O(n) | Space: O(h)


/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
    bool solve(Node* leftNode, Node* rightNode){
        if((!leftNode && rightNode) || (leftNode && !rightNode)) return false;
        if(!leftNode && !rightNode) return true;
        if(leftNode->data != rightNode->data) return false;

        bool leftAns = solve(leftNode->left, rightNode->right);
        bool rightAns = solve(leftNode->right, rightNode->left);

        return leftAns && rightAns;
    }
  public:
    bool isSymmetric(Node* root) {
        if(!root) return true;
        return solve(root->left, root->right);
        
    }
};
