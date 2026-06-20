// Problem: Single Element in Sorted Array
// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
// Difficulty: Medium
// Approach: Binary Search — check if mid is at even/odd index
// Time: O(log n) | Space: O(1)


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;

        while(l <= r){
            int mid = (r-l)+l/2;

           if(mid+1 < n && nums[mid] == nums[mid+1]){
            if(mid&1){
                r = mid-2;
            }
            else{
                l = mid+1;
            }
           }
           else if(mid-1 >= 0 && nums[mid] == nums[mid-1]){
            if(mid&1){
                l = mid+1;
            }
            else{
                r = mid-2;
            }
           }
           else{
            return nums[mid];
           }
        }
        return -1;
    }
};
