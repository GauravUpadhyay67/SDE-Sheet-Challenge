// Problem: Word Break
// Link: https://leetcode.com/problems/word-break/
// Difficulty: Medium
// Approach: Dynamic Programming (Tabulation + Hash Set + Maximum Word Length Optimization)
// Time: O(n × maxLen²)
// Space: O(n + m)


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>st(wordDict.begin(), wordDict.end());

        int maxLen = 0;
        for(auto word: wordDict){
            maxLen = max(maxLen, (int)word.size());
        }

        int n = s.size();
        vector<bool>dp(n+1, false);
        dp[0] = true;

        for(int i=1; i<=n; i++){
            for(int j=i-1; j>=max(0, i-maxLen); j--){
                if(dp[j] && st.find(s.substr(j, i-j)) != st.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
