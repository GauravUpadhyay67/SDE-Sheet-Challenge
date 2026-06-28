// Problem: Stock Span Problem
// Link: https://www.geeksforgeeks.org/the-stock-span-problem/
// Difficulty: Hard
// Approach: Monotonic Stack — find previous greater element index, span = i - pge[i]
// Time: O(n) | Space: O(n)


class StockSpanner {
public:
    int i;
    stack<pair<int, int>>st;
    StockSpanner() {
        i = -1;
    }
    
    int next(int price) {
        i++;
        while(!st.empty() && st.top().second <= price){
            st.pop();
        }

        if(st.empty()){
            st.push({i, price});
            return i+1;
        }
        else{
            int pgeIdx = st.top().first;
            st.push({i, price});
            return i - pgeIdx;
        }
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
