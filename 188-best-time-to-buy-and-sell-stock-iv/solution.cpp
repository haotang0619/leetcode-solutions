class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int ans = INT_MIN, n = prices.size();
        vector<vector<int>> dpBuy(n, vector<int>(k, INT_MAX));
        vector<vector<int>> dpSell(n, vector<int>(k, INT_MIN));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < k; j++) {
                // Buy
                int hasEarned = (j > 0 && i >= j * 2) ? dpSell[i - 1][j - 1] : 0;
                dpBuy[i][j] = prices[i] - hasEarned;
                if(i >= 1) {
                    dpBuy[i][j] = min(dpBuy[i][j], dpBuy[i - 1][j]);
                }
                
                // Sell
                if(i >= j * 2 + 1) {
                    dpSell[i][j] = max(dpSell[i - 1][j], prices[i] - dpBuy[i - 1][j]);
                    ans = max(ans, dpSell[i][j]);
                }
            }
        }
        return max(ans, 0);
    }
};
