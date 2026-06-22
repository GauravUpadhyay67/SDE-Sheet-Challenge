// Problem: Implement Max Heap
// Link: https://www.geeksforgeeks.org/max-heap-in-java/
// Difficulty: Medium
// Approach: Use priority_queue or implement heapify manually
// Time: O(log n) insert | Space: O(n)


class maxHeap {
  private:
   priority_queue<int>heap;

  public:

    void push(int x) {
        heap.push(x);
    }

    void pop() {
        if(!heap.empty()) heap.pop();
    }

    int peek() {
        int peekEl = -1;
        if(heap.size()){
            peekEl = heap.top();
        }
        return peekEl;
    }

    int size() {
        return heap.size();
    }
};
