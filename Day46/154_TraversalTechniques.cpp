// Problem: BFS / Traversal Techniques
// Link: https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
// Difficulty: Medium
// Approach: Queue + visited array — explore level by level
// Time: O(V+E) | Space: O(V)


class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int>bfs;
        int v = adj.size();
        vector<int>visited(v);
        
        queue<int>q;
        
        q.push(0);
        visited[0] = 1;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = 1;
                    q.push(neighbor);
                }
            }
        }
        return bfs;
    }
};
