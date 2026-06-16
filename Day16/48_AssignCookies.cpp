// Problem: Assign Cookies
// Link: https://leetcode.com/problems/assign-cookies/
// Difficulty: Easy
// Approach: Sort both, greedy match smallest sufficient cookie to child
// Time: O(n log n) | Space: O(1)


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size(), m = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0, j = 0;
        int cnt = 0;

        while(i < n && j < m){
            if(g[i] <= s[j]){
                cnt++;
                i++;
            }
            j++;
        }
        return cnt;
    }
};
