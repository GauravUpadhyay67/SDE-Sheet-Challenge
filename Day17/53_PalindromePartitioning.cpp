// Problem: Palindrome Partitioning
// Link: https://leetcode.com/problems/palindrome-partitioning/
// Difficulty: Hard
// Approach: Recursion — try all partitions, check if palindrome, backtrack
// Time: O(2^n * n) | Space: O(n)

class Solution {
    bool isPalindrome(string& s, int left, int right){
        while(left <= right){
            if(s[left++] != s[right--]) return false;
        }
        return true;
    }
    void solve(string& s, int index, vector<string>&arr, vector<vector<string>>&ans){
        if(index == s.size()){
            ans.push_back(arr);
            return;
        }

        for(int i=index; i<s.size(); i++){
            if(isPalindrome(s, index, i)){
                arr.push_back(s.substr(index, i-index+1));
                solve(s, i+1, arr, ans);
                arr.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<string>arr;
        vector<vector<string>>ans;
        solve(s, 0, arr, ans);
        return ans;
    }
};
