// Problem: Kth Largest Element in a Stream
// Link: https://leetcode.com/problems/kth-largest-element-in-a-stream/
// Difficulty: Hard
// Approach: Min heap of size k — maintain k largest, top = kth largest
// Time: O(log k) | Space: O(k)


class KthLargest {
    priority_queue<int, vector<int>, greater<int>>minHeap;
    int k;
public:
    KthLargest(int _k, vector<int>& nums) {
        k = _k;

        for(int x: nums){
            minHeap.push(x);

            if(minHeap.size() > k)  minHeap.pop();
        }
    }
    
    int add(int val) {
        minHeap.push(val);

        if(minHeap.size() > k) minHeap.pop();
            
        return minHeap.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
