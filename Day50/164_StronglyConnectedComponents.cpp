// Problem: Strongly Connected Components (Kosaraju's Algorithm)
// Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
// Difficulty: Hard
// Approach: Kosaraju's Algorithm — DFS to get finishing order, reverse the graph, then DFS in stack order to count SCCs
// Time: O(V+E) | Space: O(V+E)


class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st){
        vis[node] = 1;

        for(int neigh: adj[node]){
            if(!vis[neigh])  dfs(neigh, adj, vis, st);
        }
        st.push(node);
    }

    void dfs2(int node, vector<vector<int>> &revAdj, vector<int> &vis){
        vis[node] = 1;

        for(int neigh: revAdj[node]){
            if(!vis[neigh])  dfs2(neigh, revAdj, vis);
        }
    }

    int kosaraju(int V, vector<vector<int>> &edges){
        vector<vector<int>> adj(V);

        for(auto &e: edges){
            adj[e[0]].push_back(e[1]);
        }

        vector<int> vis(V, 0);
        stack<int> st;

        for(int i=0; i<V; i++){
            if(!vis[i])  dfs(i, adj, vis, st);
        }

        vector<vector<int>> revAdj(V);

        for(int i=0; i<V; i++){
            for(int neigh: adj[i]){
                revAdj[neigh].push_back(i);
            }
        }

        fill(vis.begin(), vis.end(), 0);
        int cnt = 0;

        while(!st.empty()){
            int node = st.top();
            st.pop();

            if(!vis[node]){
                cnt++;
                dfs2(node, revAdj, vis);
            }
        }
        return cnt;
    }
};
