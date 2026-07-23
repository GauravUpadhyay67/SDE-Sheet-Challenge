// Problem: Maximum Sum Increasing Subsequence
// Link: https://www.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1
// Difficulty: Medium
// Approach: Dynamic Programming — For each element, find the maximum increasing subsequence sum ending at that index
// Time: O(n²) | Space: O(n)


class Solution {
public:
    int maxSumIS(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp = arr;
        int ans = arr[0];
        
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i] > arr[j]){
                    dp[i] = max(dp[i], arr[i] + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
