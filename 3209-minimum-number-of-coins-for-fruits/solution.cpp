class Solution {
public:
    int minimumCoins(vector<int>& prices) {
        int n = prices.size();
        vector<pair<int, int>> dp(n, {1e9, 1e9});
        dp[0] = {prices[0], prices[0]};
        for(int i = 1; i < prices.size(); i++) {
            auto [bought, free] = dp[i - 1];
            dp[i].first = min(bought, free) + prices[i];
            for(int j = i - 1; j * 2 + 1 >= i; j--) {
                auto [b, f] = dp[i];
                auto [bought, free] = dp[j];
                dp[i].second = min(f, bought);
            }
        }
        return min(dp[n - 1].first, dp[n - 1].second);
    }
};
