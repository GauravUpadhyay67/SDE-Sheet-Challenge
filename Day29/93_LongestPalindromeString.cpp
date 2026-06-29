// Problem: Longest Palindrome in a String
// Link: https://leetcode.com/problems/longest-palindromic-substring/
// Difficulty: Medium
// Approach: Expand around center — for each char expand both odd & even length
// Time: O(n²) | Space: O(1)


class Solution {
public:
    string expandFromCentre(string &s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right]){
            left--;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }

    string longestPalindrome(string s) {
        int n = s.size();
        if(n < 2) return s;

        string lps = s.substr(0, 1);

        for(int i=0; i<n; i++){
            string odd = expandFromCentre(s, i, i);
            string even = expandFromCentre(s, i, i+1);

            if(odd.size() > lps.size()) lps = odd;
            if(even.size() > lps.size()) lps = even;
        }
        return lps;
    }
};
// Brute Force: Check all substrings, test if palindrome; slow but simple. O(n³) time, O(1) space.
// Expand Around Center: For every center, expand outward to find longest palindrome; more efficient. O(n²) time, O(1) space.
// Manacher's Algorithm: Transform and process string to find palindromes in linear time; fastest but complex. O(n) time, O(n) space.
