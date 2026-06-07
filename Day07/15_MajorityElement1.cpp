// Problem: Majority Element I
// Link: https://leetcode.com/problems/majority-element/
// Difficulty: Easy
// Approach: Boyer-Moore Voting Algorithm
// Time: O(n) | Space: O(1)


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0, el = -1;

        for(int i=0; i<n; i++){
            if(cnt == 0){
                el = nums[i];
                cnt++;
            }
            else if(nums[i] == el){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return el;
    }
};
