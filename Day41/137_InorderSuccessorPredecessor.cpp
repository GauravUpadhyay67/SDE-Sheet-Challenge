// Problem: Inorder Successor and Predecessor in BST
// Link: https://www.geeksforgeeks.org/inorder-successor-predecessor-given-key-bst/
// Difficulty: Medium
// Approach: BST traversal — successor is leftmost in right subtree, predecessor is rightmost in left subtree
// Time: O(h) | Space: O(1)

/* 
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
public:
    vector<Node*> findPreSuc(Node* root, int key) {
        Node* pre = NULL;
        Node* suc = NULL;

        while(root){
            if(root->data == key){

                Node* temp = root->left;
                while(temp){
                    pre = temp;
                    temp = temp->right;
                }

                temp = root->right;
                while(temp){
                    suc = temp;
                    temp = temp->left;
                }
                break;
            }
            else if(key < root->data){
                suc = root;
                root = root->left;
            }
            else{
                pre = root;
                root = root->right;
            }
        }
        return {pre, suc};
    }
};
