// Problem: Detect Cycle in Directed Graph using DFS
// Link: https://www.geeksforgeeks.org/detect-cycle-in-a-graph/
// Difficulty: Hard
// Approach: DFS + recursion stack — if neighbor in dfsStack, cycle exists
// Time: O(V+E) | Space: O(V)


class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;

        for (int neigh: adj[node]){
            if (!vis[neigh]){
                if (dfs(neigh, adj, vis, pathVis)) return true;
            }
            else if(pathVis[neigh]){
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V);

        for (auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        for (int i=0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis))  return true;
            }
        }
        return false;
    }
};
