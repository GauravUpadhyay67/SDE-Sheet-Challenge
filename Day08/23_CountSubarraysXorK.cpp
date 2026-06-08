// Problem: Count Subarrays with given XOR K
// Link: https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1
// Difficulty: Hard
// Approach: HashMap — prefix XOR, check if (xor^k) exists
// Time: O(n) | Space: O(n)


class Solution {
public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> mp;

        int xr = 0;
        long long cnt = 0;

        for (int num: arr){
            xr ^= num;

            if(xr == k)  cnt++;
            int need = xr ^ k;

            if(mp.find(need) != mp.end()){
                cnt += mp[need];
            }
                
            mp[xr]++;
        }
        return cnt;
    }
};
