// Problem: Search in Rotated Sorted Array
// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
// Difficulty: Medium
// Approach: Binary Search — identify sorted half, check if target lies in it
// Time: O(log n) | Space: O(1)


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(nums[mid] == target) return mid;

            if(nums[l] <= nums[mid]){
                if(nums[l] <= target && target < nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid] < target && target <= nums[r]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            }

        }
        return -1;
    }
};
