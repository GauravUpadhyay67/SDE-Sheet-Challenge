// Problem: Rod Cutting Problem
// Link: https://www.geeksforgeeks.org/problems/rod-cutting0840/1
// Difficulty: Hard
// Approach: Memoization (Take / Not Take)
// Time: O(n²)
// Space: O(n²) + O(n)



class Solution {
  private:
    int maxValue(vector<int>& price, int i, int n, vector<vector<int>>& dp){
        if(i == 0)  return n * price[0];
        
        if(dp[i][n] != -1) return dp[i][n];
        
        int take = 0;
        int rodLength = i+1;
        if(rodLength <= n){
            take = price[i] + maxValue(price, i, n-rodLength, dp);
        }
        
        int notTake = maxValue(price, i-1, n, dp);
        
        return dp[i][n] = max(take, notTake);
    }
    
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return maxValue(price, n-1, n,  dp);
        
    }
};
