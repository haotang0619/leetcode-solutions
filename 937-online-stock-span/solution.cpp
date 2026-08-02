class StockSpanner {
public:
    stack<pair<int, vector<int>>> sk; // [price, idx]
    int idx = 0;
    
    StockSpanner() {}
    
    int next(int price) {
        while(!sk.empty() && sk.top().first < price) sk.pop();
        int ans;
        if(sk.empty()) ans = idx + 1;
        else if(sk.top().first == price) {
            if(sk.size() == 1) ans = idx + 1;
            else {
                auto top = sk.top();
                sk.pop();
                ans = idx - sk.top().second.back();
                sk.push(top);
            }
        }
        else ans = idx - sk.top().second.back();
        if(sk.empty() || sk.top().first > price) sk.push({price, {idx++}});
        else sk.top().second.push_back(idx++);
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
