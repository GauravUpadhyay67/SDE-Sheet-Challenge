// Problem: Find Median from Data Stream
// Link: https://leetcode.com/problems/find-median-from-data-stream/
// Difficulty: Hard
// Approach: Two heaps — max heap for left half, min heap for right half
// Time: O(log n) insert, O(1) median | Space: O(n)


class MedianFinder {
    priority_queue<int>left_max_heap;
    priority_queue<int, vector<int>, greater<int>>right_min_heap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(left_max_heap.empty() || num < left_max_heap.top()){
        left_max_heap.push(num);
       }
       else{
        right_min_heap.push(num);
       }

       if(abs((int)left_max_heap.size() - (int)right_min_heap.size()) > 1){
        right_min_heap.push(left_max_heap.top());
        left_max_heap.pop();
       }
       else if(left_max_heap.size() < right_min_heap.size()){
        left_max_heap.push(right_min_heap.top());
        right_min_heap.pop();
       }

    }
    
    double findMedian() {
        int totalSize = left_max_heap.size() + right_min_heap.size();
        if(totalSize&1){
            return (int)left_max_heap.top();
        }
        else{
            return ((long long)left_max_heap.top() + (long long)right_min_heap.top())/2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
