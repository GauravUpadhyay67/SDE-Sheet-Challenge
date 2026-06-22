// Problem: Kth Largest Element in an Array
// Link: https://leetcode.com/problems/kth-largest-element-in-an-array/
// Difficulty: Medium
// Approach: Max Heap — push all elements, pop k times
// Time: O(n log n) | Space: O(n)


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>maxHeap;

        for(auto n: nums){
            maxHeap.push(n);
        }

        int s = maxHeap.size();
        int val = -1;

        while(k--){
            val = maxHeap.top();
            maxHeap.pop();
        }
        return val;
    }
};
