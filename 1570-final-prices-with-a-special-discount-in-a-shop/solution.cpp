class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> sk;
        vector<int> ans(prices.begin(), prices.end());
        for(int i = prices.size() - 1; i >= 0; i--) {
            while(!sk.empty() && sk.top() > prices[i]) sk.pop();
            if(!sk.empty()) ans[i] -= sk.top();
            sk.push(prices[i]);
        }
        return ans;
    }
};
