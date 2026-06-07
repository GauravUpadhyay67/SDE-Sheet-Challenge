// Problem: Pow(x, n)
// Link: https://leetcode.com/problems/powx-n/
// Difficulty: Easy
// Approach: Fast Exponentiation (Binary Exponentiation)
// Time: O(log n) | Space: O(1)


class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;

        if(nn < 0) nn = -1 * nn;

        while(nn){
            if(nn%2){
                ans *= x;
                nn -= 1;
            }
            else{
                nn /= 2;
                x *= x;
            }
        }

        if(n < 0) return (double)1.0 / ans;
        return ans;
    }
};
