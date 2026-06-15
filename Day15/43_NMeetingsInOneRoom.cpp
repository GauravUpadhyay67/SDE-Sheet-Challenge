// Problem: N Meetings in One Room
// Link: https://www.geeksforgeeks.org/activity-selection-problem-greedy-algo-1/
// Difficulty: Medium
// Approach: Sort by end time, greedily pick non-overlapping meetings
// Time: O(n log n) | Space: O(1)


class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        int n = start.size();
        vector<pair<int, int>>arr;
        
        for(int i=0; i<n; i++){
            arr.push_back({finish[i], start[i]});
        }
        
        sort(arr.begin(), arr.end());
        
        int cnt = 1;
        int e = arr[0].first;
        
        for(int i=1; i<n; i++){
            if(arr[i].second > e){
                cnt++;
                e = arr[i].first;
            }
        }
        return cnt;
    }
};
