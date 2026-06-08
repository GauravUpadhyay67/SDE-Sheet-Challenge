// Problem: Largest Subarray with K Sum
// Link: https://www.geeksforgeeks.org/longest-sub-array-sum-k/
// Difficulty: Medium
// Approach: HashMap — store prefix sum, check if (sum-k) exists
// Time: O(n) | Space: O(n)


class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
       int n = arr.size();
       
       unordered_map<int, int>mp;
       int ans = 0;
       int sum = 0;
       for(int i=0; i<n; i++){
           sum += arr[i];
           
           if(sum == k) ans = max(ans, i+1);
           if(mp.find(sum-k) != mp.end()) ans = max(ans, i - mp[sum-k]);
           
          if(mp.find(sum) == mp.end()){
               mp[sum] = i;
          }
       }
       return ans;
    }
};
