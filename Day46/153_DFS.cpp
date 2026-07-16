// Problem: DFS of Graph
// Link: https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/
// Difficulty: Medium
// Approach: Recursion + visited array — explore as deep as possible before backtracking
// Time: O(V+E) | Space: O(V)


class Solution {
  public:
    void dfsTraversal(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& res){
        vis[node] = 1;
        res.push_back(node);
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfsTraversal(it, adj, vis, res);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int>res;
        int v = adj.size();
        vector<int>vis(v);
        
        dfsTraversal(0, adj, vis, res);
        return res;
        
    }
};
