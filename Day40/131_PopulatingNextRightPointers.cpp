// Problem: Populating Next Right Pointers in Each Node
// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
// Difficulty: Medium
// Approach: BFS level order — connect next pointers at each level
// Time: O(n) | Space: O(1)



/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*>q;
        q.push(root);

        while(!q.empty()){
            int n = q.size();
            Node* nextNode = NULL;

            for(int i=0; i<n; i++){
                Node* node = q.front();
                q.pop();

                node->next = nextNode;
                nextNode = node;

                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
        }
        return root;
    }
};
