class Solution {
public:
    int mod = 1e9 + 7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // [price, count]
        priority_queue<pair<int, long long>> buy;
        priority_queue<pair<int, long long>, vector<pair<int, long long>>, greater<>> sell;
        long long ans = 0;
        for(auto& order : orders) {
            int p = order[0], cnt = order[1], type = order[2];
            if(type == 0) {
                while(cnt > 0 && !sell.empty() && sell.top().first <= p) {
                    auto [pSell, cntSell] = sell.top();
                    sell.pop();
                    if(cnt > cntSell) cnt -= cntSell, ans = (ans - cntSell) % mod;
                    else {
                        sell.push({pSell, cntSell - cnt});
                        ans = (ans - cnt) % mod, cnt = 0;
                    }
                }
                if(cnt > 0) buy.push({p, cnt});
                ans = (ans + cnt) % mod;
            } else {
                while(cnt > 0 && !buy.empty() && buy.top().first >= p) {
                    auto [pBuy, cntBuy] = buy.top();
                    buy.pop();
                    if(cnt > cntBuy) cnt -= cntBuy, ans = (ans - cntBuy) % mod;
                    else {
                        buy.push({pBuy, cntBuy - cnt});
                        ans = (ans - cnt) % mod, cnt = 0;
                    }
                }
                if(cnt > 0) sell.push({p, cnt});
                ans = (ans + cnt) % mod;
            }
        }
        return ans < 0 ? ans + mod : ans;
    }
};
