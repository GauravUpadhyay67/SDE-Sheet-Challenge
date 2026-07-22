// Problem: Longest Common Subsequence
// Link: https://leetcode.com/problems/longest-common-subsequence/
// Difficulty: Medium
// Approach: Dynamic Programming (Tabulation) — Build a DP table where dp[i][j] stores the LCS length for suffixes starting at i and j
// Time: O(n × m) | Space: O(n × m)


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(text1[i] == text2[j]){
                    dp[i][j] = 1 + dp[i+1][j+1];
                }
                else{
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
};
