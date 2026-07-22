// Problem: Maximum Product Subarray
// Link: https://leetcode.com/problems/maximum-product-subarray/
// Difficulty: Medium
// Approach: Traverse from both left and right while maintaining prefix and suffix products to handle negative numbers and zeros
// Time: O(n) | Space: O(1)


class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int prefix = 1;
        int suffix = 1;
        int maxProd = INT_MIN;

        for(int i=0; i<n; i++){
            prefix *= nums[i];
            suffix *= nums[n-i-1];

            maxProd = max({maxProd, prefix, suffix});

            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;
        }
        return maxProd;
    }
};
