// Problem: Maximum XOR of Two Numbers in an Array
// Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/
// Difficulty: Medium
// Approach: Trie (Bit Manipulation)
// Time: O(32 × N)
// Space: O(32 × N)


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
    int findMaximumXOR(vector<int>& nums) {

        Trie trie;

        for(int num: nums){
            trie.insert(num);
        }

        int ans = 0;

        for(int num: nums){
            ans = max(ans, trie.getMax(num));
        }

        return ans;
    }
};
