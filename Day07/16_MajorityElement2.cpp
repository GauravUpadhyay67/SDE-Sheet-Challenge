// Problem: Majority Element II
// Link: https://leetcode.com/problems/majority-element-ii/
// Difficulty: Hard
// Approach: Extended Boyer-Moore Voting — track 2 candidates
// Time: O(n) | Space: O(1)


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0;
        int el1 = -1, el2 = -1;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != el2){
                cnt1++;
                el1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != el1){
                cnt2++;
                el2 = nums[i];
            }
            else if(nums[i] == el1){
                cnt1++;
            }
            else if(nums[i] == el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;

        for(auto it: nums){
            if(it == el1) cnt1++;
            else if(it == el2) cnt2++;

        }
        
        vector<int>ans;
        if(cnt1 > n/3) ans.push_back(el1);
        if(cnt2 > n/3) ans.push_back(el2);
        return ans;
    }
};
