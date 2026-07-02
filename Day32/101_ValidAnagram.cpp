// Problem: Valid Anagram
// Link: https://leetcode.com/problems/valid-anagram/
// Difficulty: Easy
// Approach: Frequency array — count chars in s, decrement for t, check all zero
// Time: O(n) | Space: O(1)


class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(26, 0);
        for(auto c: s){
            freq[c - 'a']++;
        }
        for(auto c: t){
            freq[c - 'a']--;
            if(freq[c - 'a'] < 0) return false;
        }
        for(auto n: freq){
            if(n != 0) return false;
        }
        return true;

    }
};
