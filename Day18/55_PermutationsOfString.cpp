// Problem: Permutations of a String
// Link: https://leetcode.com/problems/permutations/
// Difficulty: Medium
// Approach: Recursion + Swap — swap each element to current position, recurse
// Time: O(n! * n) | Space: O(n)


class Solution {
    void solve(vector<int>&nums, int index, vector<vector<int>>&ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i=index; i<nums.size(); i++){
            swap(nums[i], nums[index]);
            solve(nums, index+1, ans);
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        solve(nums, 0, res);
        return res;
    }
};
