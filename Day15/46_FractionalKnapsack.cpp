// Problem: Fractional Knapsack
// Link: https://www.geeksforgeeks.org/fractional-knapsack-problem/
// Difficulty: Medium
// Approach: Sort by value/weight ratio desc, greedily pick items
// Time: O(n log n) | Space: O(1)



class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        
        vector<pair<double, pair<int, int>>>arr;
        for(int i=0; i<n; i++){
            arr.push_back({(double)val[i]/wt[i], {val[i], wt[i]}});
        }
        
        sort(arr.begin(), arr.end(), [](auto &a, auto &b){
            return a.first > b.first;
        });
        
        double ans = 0;
        
        for(int i=0; i<n; i++){
            int value = arr[i].second.first;
            int weight = arr[i].second.second;
            double fraction = arr[i].first;
            
            if(weight <= capacity){
                ans += value;
                capacity -= weight;
            }
            else{
                ans += ((double)capacity * fraction);
                capacity = 0;
                break;
            }
        }
        
        return ans;
        
        
        
    }
};
