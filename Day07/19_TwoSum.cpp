// Problem: Two Sum
// Link: https://leetcode.com/problems/two-sum/
// Difficulty: Easy
// Approach: HashMap — store complement, check in O(1)
// Time: O(n) | Space: O(n)


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;

        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) != mp.end()){
                return {i, mp[target - nums[i]]};
            }

            mp[nums[i]] = i; 
        }
        return {-1, -1};
    }
};
