// Problem: Implement atoi (String to Integer)
// Link: https://leetcode.com/problems/string-to-integer-atoi/
// Difficulty: Medium
// Approach: Skip spaces, handle sign, parse digits, clamp to INT range
// Time: O(n) | Space: O(1)


class Solution {
    bool isDigit(char c){
        if(c >= '0'  && c <= '9') return true;
        return false;
    }
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;

        while(i < n && s[i] == ' ') i++;

        int sign = 1;
        if(i < n){
            if(s[i] == '-'){
                sign = -1;
                i++;
            }
            else if(s[i] == '+') i++;
        }

        while(i < n && s[i] == '0') i++;

        long ans = 0;

        while(i < n && isDigit(s[i])){
            int digit = s[i] - '0';
            ans =  ans * 10 + digit;
            if(sign == -1 && sign * ans < INT_MIN) return INT_MIN;
            if(sign == 1 && sign * ans > INT_MAX) return INT_MAX;
            i++;
        }
        ans *= sign;
        return (int)ans;
    }
};
