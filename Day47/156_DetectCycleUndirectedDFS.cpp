// Problem: Detect Cycle in Undirected Graph using DFS
// Link: https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
// Difficulty: Hard
// Approach: DFS + parent tracking — if visited neighbor != parent, cycle exists
// Time: O(V+E) | Space: O(V)


class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;

        for (int neigh: adj[node]) {
            if (!vis[neigh]){
                if(dfs(neigh, node, adj, vis)) return true;
            }
            else if(neigh != parent){
                return true;
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {

        vector<vector<int>>adj(V);

        for (auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>vis(V, 0);

        for (int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, -1, adj, vis)) return true;
            }
        }

        return false;
    }
};


