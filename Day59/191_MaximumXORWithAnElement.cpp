// Problem: Maximum XOR With an Element From Array
// Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/
// Difficulty: Hard
// Approach: Offline Queries + Trie (Bit Manipulation)
// Time: O((N+Q) × 32 + NlogN + QlogQ)
// Space: O(32 × N + Q)

class Node{
public:

    Node* links[2];

    Node(){
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit){
        return links[bit] != nullptr;
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }
};

class Trie{

    Node* root;

public:

    Trie(){
        root = new Node();
    }

    void insert(int num){

        Node* node = root;

        for(int i=31; i>=0; i--){

            int bit = (num>>i)&1;

            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }

            node = node->get(bit);
        }
    }

    int getMax(int num){

        Node* node = root;
        int maxNum = 0;

        for(int i=31; i>=0; i--){

            int bit = (num>>i)&1;

            if(node->containsKey(1-bit)){
                maxNum |= (1<<i);
                node = node->get(1-bit);
            }
            else{
                node = node->get(bit);
            }
        }

        return maxNum;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {

        sort(nums.begin(), nums.end());

        vector<pair<int,pair<int,int>>> offlineQueries;

        for(int i=0; i<queries.size(); i++){
            offlineQueries.push_back({queries[i][1], {queries[i][0], i}});
        }

        sort(offlineQueries.begin(), offlineQueries.end());

        Trie trie;

        vector<int> ans(queries.size());

        int index = 0;

        for(auto &query: offlineQueries){

            int limit = query.first;
            int x = query.second.first;
            int queryIndex = query.second.second;

            while(index<nums.size() && nums[index]<=limit){
                trie.insert(nums[index]);
                index++;
            }

            if(index==0){
                ans[queryIndex] = -1;
            }
            else{
                ans[queryIndex] = trie.getMax(x);
            }
        }

        return ans;
    }
};
