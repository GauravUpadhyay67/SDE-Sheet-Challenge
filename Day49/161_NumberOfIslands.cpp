// Problem: Number of Islands
// Link: https://leetcode.com/problems/number-of-islands/
// Difficulty: Medium
// Approach: DFS — visit all connected land cells, mark them visited, and count connected components
// Time: O(n*m) | Space: O(n*m)


class Solution {
public:
  void solve(vector<vector<char>>& grid, int i, int j, vector<vector<int>>& vis){
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return ;
        if (vis[i][j] == 1 || grid[i][j] == '0') return ;

        vis[i][j] = 1;

        solve(grid, i + 1, j, vis);
        solve(grid, i - 1, j, vis);
        solve(grid, i, j + 1, vis);
        solve(grid, i, j - 1, vis);
    }

    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m, vector<int>(n, 0));
        int ans = 0;

        for(int i=0; i<m; ++i){
            for(int j=0; j<n; ++j){
                if(grid[i][j] != '0' && vis[i][j] == 0){
                    solve(grid, i, j, vis); 
                    ans++;
                }
            }
        }
        return ans;
    }
};
