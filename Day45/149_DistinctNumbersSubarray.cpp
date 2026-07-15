// Problem: Distinct Numbers in Each Subarray
// Link: https://www.geeksforgeeks.org/count-distinct-elements-in-every-window-of-size-k/
// Difficulty: Medium
// Approach: Sliding window + HashMap — add right, remove left, track distinct count
// Time: O(n) | Space: O(k)



class Solution {
  public:
    vector<int> countDistinct(vector<int> &nums, int k) {
       int n = nums.size();
       vector<int>ans;
       unordered_map<int, int>mp;
       
       for(int i=0; i<k; i++){
           mp[nums[i]]++;
       }
       
       ans.push_back(mp.size());
       
       int l = 0, r = k;
       
       while(r < n){
           mp[nums[l]]--;
           if(mp[nums[l]] == 0) mp.erase(nums[l]);
           mp[nums[r]]++;
           l++;
           r++;
           ans.push_back(mp.size());
       }
       return ans;
    }
};
