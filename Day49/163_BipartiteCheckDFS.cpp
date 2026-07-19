// Problem: Bipartite Graph using DFS
// Link: https://leetcode.com/problems/is-graph-bipartite/
// Difficulty: Medium
// Approach: DFS + 2-coloring — if same color neighbor found during DFS = not bipartite
// Time: O(V+E) | Space: O(V)


class Solution {
public:
    bool dfs(int node, int clr, vector<vector<int>> &graph, vector<int> &color){
        color[node] = clr;

        for(int neigh: graph[node]){
            if(color[neigh] == -1){
                if(!dfs(neigh, !clr, graph, color)){
                    return false;
                }
            }
            else if(color[neigh] == clr){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();

        vector<int>color(v, -1);

        for(int i=0; i<v; i++){
            if(color[i] == -1){
                if(!dfs(i, 0, graph, color)){
                    return false;
                }
            }
        }
        return true;
    }
};


