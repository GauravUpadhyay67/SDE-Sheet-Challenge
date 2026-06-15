// Problem: Minimum Number of Platforms for Railway
// Link: https://www.geeksforgeeks.org/minimum-number-platforms-required-railwaystation/
// Difficulty: Medium
// Approach: Sort arrival & departure, two pointer sweep
// Time: O(n log n) | Space: O(1)


class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
      int n = arr.size();
      sort(arr.begin(), arr.end());
      sort(dep.begin(), dep.end());
      
      int ans = 0, cnt = 0;
      int i = 0, j = 0;
      
      while(i < n && j < n){
          if(arr[i] <= dep[j]){
              cnt++;
              i++;
          }
          else{
              cnt--;
              j++;
          }
          ans = max(ans, cnt);
      }
      return ans;
    }
};
