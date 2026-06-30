// Problem: Longest Common Prefix
// Link: https://leetcode.com/problems/longest-common-prefix/
// Difficulty: Easy
// Approach: Compare first string char by char with all others
// Time: O(n*m) | Space: O(1)


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        string ans = "";
        string s = strs[0];

        for(int i=0; i<s.size(); i++){
            for(int j=1; j<n; j++){
                if(i >= strs[j].size() || s[i] != strs[j][i]) return ans;
            }
            ans += s[i];
        }
        return ans;
    }
};
