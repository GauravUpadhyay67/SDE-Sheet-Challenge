// Problem: Super Egg Drop
// Link: https://leetcode.com/problems/super-egg-drop/
// Difficulty: Hard
// Approach: Memoization + Binary Search
// Time: O(k × n × log n)
// Space: O(k × n)


class Solution {
private:
    vector<vector<int>> dp;

    int solve(int eggs, int floors){
        if(floors == 0 || floors == 1) return floors;
        if(eggs == 1) return floors;

        if (dp[eggs][floors] != -1){
            return dp[eggs][floors];
        }

        int low = 1;
        int high = floors;
        int ans = INT_MAX;

        while(low <= high){
            int mid = low + (high-low)/2;

            int breaks = solve(eggs-1, mid-1);
            int survives = solve(eggs, floors-mid);

            int temp = 1 + max(breaks, survives);

            ans = min(ans, temp);

            if(breaks > survives){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return dp[eggs][floors] = ans;
    }

public:
    int superEggDrop(int k, int n) {
        dp.assign(k+1, vector<int>(n+1, -1));
        return solve(k, n);
    }
};
