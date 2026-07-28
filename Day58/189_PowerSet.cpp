// Problem: Power Set
// Link: https://www.geeksforgeeks.org/problems/power-set4302/1
// Difficulty: Medium
// Approach: Bit Manipulation
// Time: O(N × 2^N)
// Space: O(2^N)


class Solution {
  public:
    vector<string> powerSet(string &s) {
        int n = s.size();
        vector<string> ans;

        for(int m=0; m<(1<<n); m++){
            string temp = "";

            for(int i=0; i<n; i++){

                if(m & (1<<i)){
                    temp += s[i];
                }
            }
            ans.push_back(temp);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};



