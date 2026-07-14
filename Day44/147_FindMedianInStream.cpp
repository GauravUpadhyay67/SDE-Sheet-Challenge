// Problem: Find Median in a Stream
// Link: https://leetcode.com/problems/find-median-from-data-stream/
// Difficulty: Medium
// Approach: Two heaps — max heap left half, min heap right half
// Time: O(log n) | Space: O(n)



class MedianFinder {
    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxHeap.empty() || num <= maxHeap.top()){
            maxHeap.push(num);
        }
        else{
            minHeap.push(num);
        }

        if(maxHeap.size() > minHeap.size() + 1){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if(minHeap.size() > maxHeap.size()){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        int m = maxHeap.size();
        int n = minHeap.size();

        double ans = 0;

        if((m+n)&1){
            ans = maxHeap.top();
        }
        else{
            ans = (maxHeap.top() + minHeap.top())/2.0;
        }
        
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
