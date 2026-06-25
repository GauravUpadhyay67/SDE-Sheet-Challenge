// Problem: Sort a Stack
// Link: https://www.geeksforgeeks.org/sort-a-stack-using-recursion/
// Difficulty: Medium
// Approach: Recursion — pop all, insert each element in sorted position
// Time: O(n²) | Space: O(n)


class Solution {
    void sortMyStack(stack<int> &st, int val){
        if(st.empty() || st.top() <= val){
            st.push(val);
            return;
        }
        int v = st.top();
        st.pop();
        sortMyStack(st, val);
        st.push(v);
    }
    
    void solve(stack<int> &st){
        if(st.empty()) return;
        
        int val = st.top();
        st.pop();
        solve(st);
        sortMyStack(st, val);
    }
  public:
    void sortStack(stack<int> &st) {
        solve(st);
        
    }
};
