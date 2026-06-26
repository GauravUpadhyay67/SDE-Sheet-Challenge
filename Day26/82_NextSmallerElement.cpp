// Problem: Next Smaller Element
// Link: https://www.geeksforgeeks.org/next-smaller-element/
// Difficulty: Medium
// Approach: Monotonic Stack — maintain decreasing stack, current element is next smaller for popped elements
// Time: O(n) | Space: O(n)


class Solution {
  public:
    vector<int> nextSmallerEle(vector<int>& arr) {
        int n = arr.size();
        stack<int>st;
        vector<int>ans(n);
        
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && st.top() >= arr[i]){
                st.pop();
            }
            
            ans[i] = st.empty() ? -1 : st.top();
            st.push(arr[i]);
        }
        return ans;
    }
};
