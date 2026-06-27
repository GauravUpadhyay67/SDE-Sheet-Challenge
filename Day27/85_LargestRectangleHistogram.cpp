// Problem: Largest Rectangle in Histogram
// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/
// Difficulty: Hard
// Approach: Monotonic Stack — find left & right smaller boundary for each bar
// Time: O(n) | Space: O(n)


class Solution {
    void findNSE(vector<int>&arr, vector<int>& nse){
        int n = arr.size();
        stack<int>st;
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            nse[i] = (st.empty() ? n : st.top());
            st.push(i);
        }
    }
    
    void findPSE(vector<int>&arr, vector<int>& pse){
        int n = arr.size();
        stack<int>st;
        
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            pse[i] = (st.empty() ? -1 : st.top());
            st.push(i);
        }
    }

public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        vector<int>nse(n), pse(n);
        
        findNSE(arr, nse);
        findPSE(arr, pse);
        int ans = 0;
        
        for(int i=0; i<n; i++){
            int width = (nse[i] - pse[i] - 1);
            ans = max(ans, width * arr[i]);
        }
        return ans;
    }
};
