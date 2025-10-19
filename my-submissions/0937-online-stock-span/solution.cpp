class StockSpanner {
public:
    int i = 0;
    stack<pair<int, int>> s;
    StockSpanner() {
    }
    
    int next(int price) {
        while (!s.empty() && s.top().second <= price) s.pop();
        if (s.empty()) {
            s.push(make_pair(i, price));
            i++;
            return i;
        }
        int span = i - s.top().first;
        s.push(make_pair(i, price));
        i++;
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
