// Problem: Subset Sums
// Link: https://www.geeksforgeeks.org/subset-sum-problem/
// Difficulty: Hard
// Approach: Recursion — include/exclude each element, collect all sums
// Time: O(2^n) | Space: O(2^n)


class Solution {
    void solve(vector<int>&arr, int i, int sum, vector<int>&ans){
        if(i < 0){
            ans.push_back(sum);
            return;
        }
        
        solve(arr, i-1, sum+arr[i], ans);
        solve(arr, i-1, sum, ans);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        int n = arr.size();
        
        vector<int>ans;
        int sum = 0;
        solve(arr, n-1, sum, ans);
        return ans;
    }
};
