// Problem: Combination Sum II
// Link: https://leetcode.com/problems/combination-sum-ii/
// Difficulty: Medium
// Approach: Sort + Recursion, skip duplicates at same level, each element once
// Time: O(2^n) | Space: O(n)


class Solution {
    void solve(vector<int>& nums, int index, int target, vector<int>& comb, vector<vector<int>>& ans){
        if(target == 0) {
            ans.push_back(comb);
            return;
        }
        if(index == nums.size()) return;

        for(int i=index; i<nums.size(); i++){
            if(i > index && nums[i] == nums[i-1]) continue;

            if(nums[i] <= target){
                comb.push_back(nums[i]);
                solve(nums, i+1, target-nums[i], comb, ans);
                comb.pop_back();
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> comb;
        solve(candidates, 0, target, comb, ans);
        return ans;
    }
};
