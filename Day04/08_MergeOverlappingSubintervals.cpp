// Problem: Merge Intervals
// Link: https://leetcode.com/problems/merge-intervals/
// Difficulty: Medium
// Approach: Sort by start time, merge if overlapping
// Time: O(n log n) | Space: O(n)

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>>ans;
        int start = intervals[0][0], end = intervals[0][1];

        for(int i=0; i<n; i++){
            if(intervals[i][0] <= end){
                end = max(intervals[i][1], end);
            }
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        ans.push_back({start, end});
        return ans;
    }
};
