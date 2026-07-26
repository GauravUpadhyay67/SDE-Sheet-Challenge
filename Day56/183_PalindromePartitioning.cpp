// Problem: Palindrome Partitioning II
// Link: https://leetcode.com/problems/palindrome-partitioning-ii/
// Difficulty: Hard
// Approach: Memoization
// Time: O(n³)
// Space: O(n²)


class Solution {
    bool isPalindrome(string& s, int left, int right){
        while(left <= right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }

    int solve(string& s, int index, vector<int>&dp){
        if(index == s.size()) return 0;
        if(dp[index] != -1) return dp[index];

        int res = INT_MAX;

        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                int partitions = 1 + solve(s, i+1, dp);
                res = min(res, partitions);
            }
        }

        return dp[index] = res;
    }
public:
    int minCut(string s) {
        vector<int>dp(s.size(), -1);
        return solve(s, 0, dp)-1;
    }
};
