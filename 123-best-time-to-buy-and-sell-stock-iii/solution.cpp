class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = INT_MIN, n = prices.size();
        vector<vector<int>> dpBuy(n, vector<int>(2, INT_MAX));
        vector<vector<int>> dpSell(n, vector<int>(2, INT_MIN));
        for(int i = 0; i < n; i++) {
            dpBuy[i][0] = prices[i];
            if(i >= 1) {
                dpBuy[i][0] = min(dpBuy[i][0], dpBuy[i - 1][0]);
                dpSell[i][0] = max(dpSell[i - 1][0], prices[i] - dpBuy[i - 1][0]);
                ans = max(ans, dpSell[i][0]);
            }
            if(i >= 2) {
                int hasEarned = dpSell[i - 1][0];
                dpBuy[i][1] = min(dpBuy[i - 1][1], prices[i] - hasEarned);
            }
            if(i >= 3) {
                dpSell[i][1] = max(dpSell[i - 1][1], prices[i] - dpBuy[i - 1][1]);
                ans = max(ans, dpSell[i][1]);
            }
        }
        return max(ans, 0);
    }
};
