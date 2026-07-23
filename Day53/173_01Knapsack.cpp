// Problem: 0/1 Knapsack
// Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
// Difficulty: Hard
// Approach: Dynamic Programming (Tabulation) — For every item, decide whether to take it or skip it while building the solution from the end
// Time: O(n × W) | Space: O(n × W)


class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        
        vector<vector<int>>dp(n + 1, vector<int>(W + 1, 0));
        
        for(int i = n - 1; i >= 0; i--){
            for(int w = 0; w <= W; w++){
                int notTake = dp[i + 1][w];
                int take = 0;
                
                if(wt[i] <= w){
                    take = val[i] + dp[i + 1][w - wt[i]];
                }
                
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[0][W];
    }
};
