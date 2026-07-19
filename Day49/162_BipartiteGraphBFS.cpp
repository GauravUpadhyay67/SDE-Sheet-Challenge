// Problem: Bipartite Graph using BFS
// Link: https://leetcode.com/problems/is-graph-bipartite/
// Difficulty: Medium
// Approach: BFS + 2-coloring — assign alternate colors, if same color neighbor found = not bipartite
// Time: O(V+E) | Space: O(V)


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int>color(v, -1);

        for(int i=0; i<v; i++){
            if(color[i] != -1) continue;

            queue<int> q;
            q.push(i);
            color[i] = 0;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int neigh: graph[node]){
                    if(color[neigh] == -1){
                        color[neigh] = !color[node];
                        q.push(neigh);
                    }
                    else if(color[neigh] == color[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
