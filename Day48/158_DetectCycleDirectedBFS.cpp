// Problem: Detect Cycle in Directed Graph using BFS
// Link: https://www.geeksforgeeks.org/detect-cycle-in-a-directed-graph-using-bfs/
// Difficulty: Hard
// Approach: Kahn's Algorithm — if topo sort includes all V nodes, no cycle; else cycle exists
// Time: O(V+E) | Space: O(V)

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {

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

        int cnt = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();
            cnt++;

            for(int neigh: adj[node]){
                indegree[neigh]--;

                if(indegree[neigh] == 0){
                    q.push(neigh);
                }
            }
        }

        return cnt != V;
    }
};
