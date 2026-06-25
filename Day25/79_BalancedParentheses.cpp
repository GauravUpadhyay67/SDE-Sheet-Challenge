// Problem: Balanced Parentheses
// Link: https://leetcode.com/problems/valid-parentheses/
// Difficulty: Easy
// Approach: Stack — push opening, pop and match on closing
// Time: O(n) | Space: O(n)


class Solution {
public:
    bool isValid(string s) {
        stack<int>st;

        for(auto c: s){
            if(st.empty() || c == '(' || c == '{' || c == '['){
                st.push(c);
            }
            else{
                char t = st.top();
                if((c == ')' && t == '(') || (c == '}' && t == '{') || (c == ']' && t == '[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }
        }
        return st.empty();
    }
};
