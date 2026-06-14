// Problem: Remove Duplicates from Sorted Array
// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// Difficulty: Easy
// Approach: Two pointers — slow and fast
// Time: O(n) | Space: O(1)



class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int l = 0;

        for(int r=0; r<n; r++){
            if(nums[l] != nums[r]){
                nums[++l] = nums[r];
            }
        }
        return l+1;
    }
};
