// Problem: Topological Sort DFS
// Link: https://www.geeksforgeeks.org/problems/topological-sort/1
// Difficulty: Medium
// Approach: DFS + stack — push node to stack after all neighbors processed
// Time: O(V+E) | Space: O(V)


class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;

        for(int neigh: adj[node]){
            if(!vis[neigh]){
                dfs(neigh, adj, vis, st);
            }
        }

        st.push(node);
    }

    vector<int> topoSort(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
