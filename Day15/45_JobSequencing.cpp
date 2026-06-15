// Problem: Job Sequencing Problem
// Link: https://www.geeksforgeeks.org/job-sequencing-problem/
// Difficulty: Medium
// Approach: Sort by profit desc, greedily assign to latest available slot
// Time: O(n log n) | Space: O(n)



class Solution {
    int find(int x, vector<int>& arr){

        if(arr[x] == x)
            return x;

        return arr[x] = find(arr[x], arr);
    }
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        int n = profit.size();
        int maxDeadline = -1;
        vector<pair<int, int>>job;
        
        for(int i=0; i<n; i++){
            job.push_back({profit[i], deadline[i]});
            maxDeadline = max(maxDeadline, deadline[i]);
        }
        
        sort(job.begin(), job.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });
        
        int jobCount = 0, maxProfit = 0;
        vector<int>arr(maxDeadline+1);
        
        for(int i=0; i<=maxDeadline; i++){
            arr[i] = i;
        }
        
        for(int i=0; i<n; i++){
            int p = job[i].first;
            int d = job[i].second;
            
            int slot = find(d, arr);
            
            if(slot > 0){
                maxProfit += p;
                jobCount++;
                
                arr[slot] = find(slot - 1, arr);
            }
        }
        return {jobCount, maxProfit};
        
    }
};
