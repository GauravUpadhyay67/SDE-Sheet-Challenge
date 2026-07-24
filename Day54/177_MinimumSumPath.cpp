// Problem: Minimum Sum Path
// Link: https://leetcode.com/problems/minimum-path-sum/
// Difficulty: Medium
// Approach: Dynamic Programming (Tabulation) — Compute the minimum cost to reach each cell using the top and left cells
// Time: O(n × m) | Space: O(n × m)


class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>dp(n, vector<int>(m));

        dp[0][0] = grid[0][0];

        for(int i=1; i<n; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }

        for(int j=1; j<m; j++){
            dp[0][j] = dp[0][j-1] + grid[0][j];
        }

        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j] = grid[i][j] + min(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n-1][m-1];
    }
};
