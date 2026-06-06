class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        vector<long long> pSum1(n, 0), pSum2(n, 0);
        for(int i = 0; i < n; i++) {
            long long prev1 = i > 0 ? pSum1[i - 1] : 0;
            long long prev2 = i > 0 ? pSum2[i - 1] : 0;
            pSum1[i] = prev1 + (long long)prices[i] * strategy[i];
            pSum2[i] = prev2 + prices[i];
        }
        long long ans = pSum1[n - 1];
        for(int i = 0; i <= n - k; i++) {
            long long now1 = i > 0 ? pSum1[i - 1] : 0;
            long long now2 = pSum2[i + k - 1] - pSum2[i + k / 2 - 1];
            long long now3 = pSum1[n - 1] - pSum1[i + k - 1];
            ans = max(ans, now1 + now2 + now3);
        }
        return ans;
    }
};
