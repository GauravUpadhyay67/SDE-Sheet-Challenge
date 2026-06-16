// Problem: Minimum Coins (Coin Change)
// Link: https://leetcode.com/problems/coin-change/
// Difficulty: Hard
// Approach: DP (Tabulation) — dp[i][amt] = min coins using first i+1 coins for amt
// Time: O(n * amount) | Space: O(n * amount)


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        
        for(int amt=0; amt<=amount; amt++){
            if(amt % coins[0] == 0) dp[0][amt] = amt / coins[0];
            else dp[0][amt] = 1e9;
        }

        for(int i=1; i<n; i++){
            for(int amt=0; amt<=amount; amt++){
                int take = 1e9;
                if(amt >= coins[i]) take = 1 + dp[i][amt-coins[i]];
                int notTake = dp[i-1][amt];

                dp[i][amt] = min(take, notTake);
            }
        }
        int minCoins = dp[n-1][amount];
        return minCoins >= 1e9 ? -1 : minCoins;
    }
};


// class Solution {
//     int solve(vector<int>& coins, int amount, int i, vector<vector<int>>&dp){
//         if(i == 0){
//             if(amount % coins[0] == 0) return dp[i][amount] = amount / coins[0];
//             else return 1e9;
//         }
//         if(dp[i][amount] != -1) return dp[i][amount];

//         int take = 1e9;
//         if(amount >= coins[i]) take = 1 + solve(coins, amount-coins[i], i, dp);

//         int notTake = solve(coins, amount, i-1, dp);

//         return dp[i][amount] = min(take, notTake);
//     }
// public:
//     int coinChange(vector<int>& coins, int amount) {
//         int n = coins.size();
//         vector<vector<int>>dp(n, vector<int>(amount+1, -1));
//         solve(coins, amount, n-1, dp);
//         int minCoins = dp[n-1][amount];
//         return minCoins >= 1e9 ? -1 : minCoins;
//     }
// };
