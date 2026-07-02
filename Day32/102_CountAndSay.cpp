// Problem: Count and Say
// Link: https://leetcode.com/problems/count-and-say/
// Difficulty: Hard
// Approach: Iteratively build each sequence by counting consecutive chars
// Time: O(n × m) | Space: O(m)

class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        for(int i=2; i<=n; i++){
            string curr = "";
            int cnt = 1;

            for(int j=1; j<=ans.size(); j++){
                if(j < ans.size() && ans[j] == ans[j-1]){
                    cnt++;
                }
                else{
                    curr += to_string(cnt);
                    curr += ans[j-1];
                    cnt = 1;
                }
            }
            ans = curr;
        }
        return ans;
    }
};
