// Problem: Reverse Every Word in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium
// Approach: Split by spaces, reverse each word, join back
// Time: O(n) | Space: O(n)


class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";

        reverse(s.begin(), s.end());

        for(int i = 0; i < n; i++){
            while(i < n && s[i] == ' ') i++;

            string word;
            while(i < n && s[i] != ' '){
                word.push_back(s[i]);
                i++;
            }

            if(!word.empty()){
                reverse(word.begin(), word.end());
                res += word + " ";
            }
        }
        if(!res.empty()) res.pop_back();
        return res;
    }
};
