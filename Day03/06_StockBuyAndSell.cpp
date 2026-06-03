// Problem: Best Time to Buy and Sell Stock
// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Difficulty: Easy
// Approach: Track minimum price, update max profit at each step
// Time: O(n) | Space: O(1)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0;
        int buy = prices[0];

        for(int i=0; i<n; i++){
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i]-buy);
        }
        return profit;
    }
};
