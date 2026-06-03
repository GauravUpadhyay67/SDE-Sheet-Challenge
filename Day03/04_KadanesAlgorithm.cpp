// Problem: Kadane's Algorithm (Maximum Subarray)
// Link: https://leetcode.com/problems/maximum-subarray/
// Difficulty: Medium
// Approach: Track current sum, reset if negative, update max
// Time: O(n) | Space: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int ans = INT_MIN;

        for(int i=0; i<n; i++){
            sum += nums[i];
            ans = max(ans, sum);

            if(sum <= 0){
                sum = 0;
            }
        }

        return ans;
    }
};
