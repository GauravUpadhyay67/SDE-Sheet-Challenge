// Problem: Find the Repeating and Missing Number
// Link: https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/
// Difficulty: Hard
// Approach: Math — use sum and sum of squares formulas to find both numbers
// Time: O(n) | Space: O(1)


class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        long long n = arr.size();
        
        long long sum1 = 0, sum2 = 0;
        long long naturalSum1 = (n * (n+1))/2;
        long long naturalSum2 = (n * (n+1) * ((2*n) + 1))/6;
        
        for(int i=0; i<n; i++){
            sum1 += arr[i];
            sum2 += (1LL * arr[i] * arr[i]);
        }
        
        long long val1 = sum1 - naturalSum1;  // x-y
        long long val2 = sum2 - naturalSum2;
        
        val2 = val2/val1;   // x+y
        
        long long rVal = (val1 + val2)/2;
        long long mVal = val2 - rVal;
        
        return {(int)rVal, (int)mVal};
        
        
    }
};
