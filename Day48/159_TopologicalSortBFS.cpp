// Problem: Topological Sort BFS (Kahn's Algorithm)
// Link: https://www.geeksforgeeks.org/problems/topological-sort/1
// Difficulty: Medium
// Approach: Indegree array + queue — push 0 indegree nodes, reduce neighbors indegree
// Time: O(V+E) | Space: O(V)

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>>adj(V);
        vector<int>indegree(V, 0);

        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;

        for(int i=0; i<V; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(int neigh: adj[node]){
                indegree[neigh]--;

                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return ans;
    }
};
