// Problem: Subset Sum Equals Target
// Link: https://www.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1
// Difficulty: Medium
// Approach: Memoization (Take / Not Take)
// Time: O(n × target)
// Space: O(n × target) + O(n)


class Solution {
private:
    bool solve(vector<int>& arr, int i, int target, vector<vector<int>>& dp){
        if(target == 0) return true;

        if(i == 0){
            return arr[0] == target;
        }

        if(dp[i][target] != -1){
            return dp[i][target];
        }

        bool notTake = solve(arr, i-1, target, dp);

        bool take = false;

        if(arr[i] <= target){
            take = solve(arr, i-1, target-arr[i], dp);
        }

        return dp[i][target] = take || notTake;
    }

public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>>dp(n, vector<int>(target + 1, -1));

        return solve(arr, n-1, target, dp);
    }
};
