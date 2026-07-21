// Problem: Floyd Warshall Algorithm
// Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
// Difficulty: Medium
// Approach: Dynamic Programming — Treat every vertex as an intermediate node and relax all pairs of vertices using the Floyd-Warshall algorithm
// Time: O(V³) | Space: O(1)



class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
        
        int v = dist.size();
        const int INF = 100000000;
        
        for(int x=0; x<v; x++){
            for(int i=0; i<v; i++){
                for(int j=0; j<v; j++){
                    
                    if(dist[i][x] == INF || dist[x][j] == INF){
                        continue;
                    }
                    
                    dist[i][j] = min(dist[i][j], dist[i][x] + dist[x][j]);
                }
            }
        }
    }
};
