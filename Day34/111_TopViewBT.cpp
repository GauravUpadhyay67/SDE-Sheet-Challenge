// Problem: Top View of Binary Tree
// Link: https://www.geeksforgeeks.org/print-nodes-top-view-binary-tree/
// Difficulty: Medium
// Approach: BFS + HashMap — track horizontal distance, store first node seen
// Time: O(n log n) | Space: O(n)



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
    vector<int> topView(Node *root) {
        // code here
        vector<int>ans;
        map<int, Node*>mp;
        queue<pair<int, Node*>>q;
        
        q.push({0, root});
        
        while(!q.empty()){
            int col = q.front().first;
            Node* node = q.front().second;
            q.pop();
            
            if(node->left) q.push({col-1, node->left});
            if(node->right) q.push({col+1, node->right});
            
            if(mp.find(col) == mp.end()) mp[col] = node;
        }
        
        for(auto it: mp){
            ans.push_back((it.second)->data);
        }
        return ans;
    }
};
