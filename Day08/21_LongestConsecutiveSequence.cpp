// Problem: Longest Consecutive Sequence
// Link: https://leetcode.com/problems/longest-consecutive-sequence/
// Difficulty: Medium
// Approach: HashSet — for each sequence start, expand and count
// Time: O(n) | Space: O(n)


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        for(int e: nums) st.insert(e);

        int longest = 0;

        for(auto num: st){
            if(st.find(num-1) == st.end()){
                int cnt = 1;
                while(st.find(num+1) != st.end()){
                    cnt++;
                    num++;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};
