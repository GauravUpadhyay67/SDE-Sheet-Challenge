// Problem: Detect Cycle in Undirected Graph using BFS
// Link: https://www.geeksforgeeks.org/detect-cycle-undirected-graph/
// Difficulty: Hard
// Approach: BFS + parent tracking — if visited neighbor != parent, cycle exists
// Time: O(V+E) | Space: O(V)


class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);

        for(int i=0; i<V; i++){
            if(vis[i]) continue;

            queue<pair<int,int>>q;
            q.push({i, -1});
            vis[i] = 1;

            while(!q.empty()){
                auto [node, parent] = q.front();
                q.pop();

                for(int neigh: adj[node]){

                    if(!vis[neigh]){
                        vis[neigh] = 1;
                        q.push({neigh, node});
                    }
                    else if(neigh != parent){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
