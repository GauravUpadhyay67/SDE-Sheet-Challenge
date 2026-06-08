// Problem: Longest Substring Without Repeating Characters
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
// Difficulty: Medium
// Approach: Sliding Window + HashMap
// Time: O(n) | Space: O(n)


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int>mp;

        int i = 0, j = 0;
        int ans = 0;

        while(j < n){
            if(mp.find(s[j]) != mp.end()){
                i = max(i, mp[s[j]] + 1);
            }

            mp[s[j]] = j;

            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
