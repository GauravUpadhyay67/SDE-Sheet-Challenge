// Problem: Implement Stack using Arrays
// Link: https://www.geeksforgeeks.org/implement-stack-using-array/
// Difficulty: Easy
// Approach: Array with top pointer, push/pop at top
// Time: O(1) push/pop | Space: O(n)


class myStack {
    vector<int>st;
    int top;
    int n;
    
  public:
    myStack(int n) {
        st.resize(n);
        top = -1;
    }

    bool isEmpty() {
      return top == -1;
    }

    bool isFull() {
        return top == st.size()-1;
    }

    void push(int x) {
       if(!isFull()) st[++top] = x;
    }

    void pop() {
        if(!isEmpty()) --top;
    }

    int peek() {
        if(!isEmpty()) return st[top];
        
        return -1;
    }
};
