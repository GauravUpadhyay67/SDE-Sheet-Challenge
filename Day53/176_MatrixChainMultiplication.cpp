// Problem: Matrix Chain Multiplication
// Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
// Difficulty: Hard
// Approach: Dynamic Programming (Tabulation) — Try every partition point and choose the minimum multiplication cost
// Time: O(n³) | Space: O(n²)


class Solution {
public:
    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();
        
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i=n-1; i>=1; i--){
            for(int j=i+1; j<n; j++){
                dp[i][j] = INT_MAX;
                
                for(int k=i; k<j; k++){
                    int cost = arr[i-1] * arr[k] * arr[j] + dp[i][k] + dp[k+1][j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }
        return dp[1][n-1];
    }
};



