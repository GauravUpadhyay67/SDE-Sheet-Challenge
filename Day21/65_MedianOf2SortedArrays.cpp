// Problem: Median of 2 Sorted Arrays
// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/
// Difficulty: Hard
// Approach: Merge both sorted arrays, find median from merged array
// Time: O(n+m) | Space: O(n+m)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int i = 0, j = 0;
        vector<int>temp;

        while(i < m && j < n){
            if(nums1[i] < nums2[j]) temp.push_back(nums1[i++]);
            else temp.push_back(nums2[j++]);
        }

        while(i < m) temp.push_back(nums1[i++]);
        while(j < n) temp.push_back(nums2[j++]);

        int newSize = m+n;
        double ans = 0;
        if(newSize&1){
            ans = temp[newSize/2];
        }
        else{
            ans = (temp[newSize/2] + temp[(newSize/2)-1])/2.0;
        }
        return ans;

    }
};
