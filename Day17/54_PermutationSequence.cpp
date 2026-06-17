// Problem: Permutation Sequence
// Link: https://leetcode.com/problems/permutation-sequence/
// Difficulty: Medium
// Approach: Math — use factorial to find kth permutation directly
// Time: O(n²) | Space: O(n)


class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int>numbers;
        for(int i=1; i<n; i++){
            fact *= i;
            numbers.push_back(i);
        }
        numbers.push_back(n);

        string ans = "";
        k -= 1;

        while(1){
            int pos = k/fact;
            ans += to_string(numbers[pos]);
            numbers.erase(numbers.begin()+pos);

            if(numbers.size() == 0) break;

            k %= fact;
            fact /= numbers.size();
        }
        return ans;

    }
};
