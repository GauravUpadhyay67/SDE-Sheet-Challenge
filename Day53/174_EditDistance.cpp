// Problem: Edit Distance
// Link: https://leetcode.com/problems/edit-distance/
// Difficulty: Hard
// Approach: Dynamic Programming (Tabulation) — Compute the minimum operations required by considering insert, delete, and replace
// Time: O(n × m) | Space: O(n × m)


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1, vector<int>(m+1));

        for(int i=0; i<=n; i++){
            dp[i][m] = n-i;
        }

        for(int j=0; j<=m; j++){
            dp[n][j] = m-j;
        }

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int insert = dp[i][j+1];
                    int del = dp[i+1][j];
                    int replace = dp[i+1][j+1];

                    dp[i][j] = 1 + min({insert, del, replace});
                }
            }
        }
        return dp[0][0];
    }
};


