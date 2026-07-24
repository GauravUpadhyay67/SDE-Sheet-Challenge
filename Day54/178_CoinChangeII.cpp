// Problem: Coin Change II
// Link: https://leetcode.com/problems/coin-change-ii/
// Difficulty: Medium
// Approach: Memoization (Take / Not Take)
// Time: O(n × amount)
// Space: O(n × amount) + O(amount)


class Solution {
    private:
    int solve(vector<int>& coins, int i, int amount, vector<vector<int>>&dp){
        if(amount == 0) return 1;

        if(i == 0){
            if(amount % coins[0] == 0) return 1;
            return 0;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 0;
        if(coins[i] <= amount) take = solve(coins, i, amount-coins[i], dp);

        int notTake = solve(coins, i-1, amount, dp);

        return dp[i][amount] = take + notTake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return solve(coins, n-1, amount, dp);
    }
};
