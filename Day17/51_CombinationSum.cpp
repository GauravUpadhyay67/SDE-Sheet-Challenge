// Problem: Combination Sum
// Link: https://leetcode.com/problems/combination-sum/
// Difficulty: Medium
// Approach: Recursion — pick same element multiple times, backtrack
// Time: O(2^t) t=target | Space: O(t)

class Solution {
    void solve(vector<int>&nums, int index, int target, vector<int>&arr, vector<vector<int>>&ans){

        for(int i=index; i<nums.size(); i++){
            if(nums[i] <= target){
                arr.push_back(arr[i])
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>>ans;
        vector<int>arr;

        solve(candidates, 0, target, arr, ans);
        return ans;
    }
};
