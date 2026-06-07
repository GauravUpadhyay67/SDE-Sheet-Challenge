// Problem: Grid Unique Paths
// Link: https://leetcode.com/problems/unique-paths/
// Difficulty: Medium
// Approach: DP — dp[i][j] = dp[i-1][j] + dp[i][j-1]
// Time: O(n*m) | Space: O(n*m)


class Solution {
    int solve(int i, int j, vector<vector<int>>& dp){
        if(i == 0 && j == 0) return 1;
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = solve(i, j-1, dp);
        int top = solve(i-1, j, dp);

        return dp[i][j] = left + top;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return solve(m-1, n-1, dp);
    }
};
