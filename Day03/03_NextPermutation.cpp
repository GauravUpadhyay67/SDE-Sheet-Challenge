// Problem: Next Permutation
// Link: https://leetcode.com/problems/next-permutation/
// Difficulty: Medium
// Approach: Find breakpoint from right, swap with next greater, reverse suffix
// Time: O(n) | Space: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int peakEl = -1;

        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                peakEl = i;
                break;
            }
        }

        if(peakEl != -1){
            int minValIdx = -1;
            for(int i=peakEl+1; i<n; i++){
                if(nums[i] > nums[peakEl]){
                    if(minValIdx == -1 || nums[i] < nums[minValIdx]){
                        minValIdx = i;
                    }
                }
            }

            swap(nums[minValIdx], nums[peakEl]);
            sort(nums.begin()+peakEl+1, nums.end());
        }
        else{
            reverse(nums.begin(), nums.end());
        }
    }
};
