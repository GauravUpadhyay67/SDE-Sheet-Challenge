// Problem: Trapping Rainwater
// Link: https://leetcode.com/problems/trapping-rain-water/
// Difficulty: Hard
// Approach: Two pointers — track leftMax and rightMax
// Time: O(n) | Space: O(1)


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int lmax = 0, rmax = 0;
        int ans = 0;

        while(l < r){
            lmax = max(lmax, height[l]);
            rmax = max(rmax, height[r]);
            if(lmax < rmax){
                ans += (lmax - height[l++]);
            }
            else{
                ans += (rmax - height[r--]);
            }
        }
        return ans;
    }
};
