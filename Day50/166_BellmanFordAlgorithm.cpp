// Problem: Bellman-Ford Algorithm
// Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Difficulty: Hard
// Approach: Relax all edges V-1 times, then perform one extra iteration to detect negative weight cycles
// Time: O(V*E) | Space: O(V)


class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int> dist(V, 1e8);
        dist[src] = 0;

        for(int i=0; i<V-1; i++){
            for(auto &e: edges){
                int u = e[0];
                int v = e[1];
                int wt = e[2];

                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }

        for(auto &e: edges){
            int u = e[0];
            int v = e[1];
            int wt = e[2];

            if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                return {-1};
            }
        }
        return dist;
    }
};
