// Problem: 3 Sum
// Link: https://leetcode.com/problems/3sum/
// Difficulty: Medium
// Approach: Sort + Two Pointers — fix one element, use two pointer for rest
// Time: O(n²) | Space: O(1)


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for(int i=0; i<n; i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;

            while(j < k){
                long sum = (long)nums[i] + nums[j] + nums[k];

                if(sum == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]) j++;
                    while(j < k && nums[k] == nums[k+1]) k--;
                }
                else if(sum > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};
