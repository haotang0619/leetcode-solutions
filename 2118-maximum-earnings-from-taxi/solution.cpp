class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        vector<vector<pair<int, int>>> v(n + 1, vector<pair<int, int>>({}));
        for(auto x : rides) {
            int l = x[0], r = x[1], t = x[2];
            int money = r - l + t;
            v[r].push_back({l, money});
        }
        vector<long long> dp(n + 1, 0);
        for(int r = 1; r <= n; r++) {
            for(auto x : v[r]) {
                auto [l, money] = x;
                dp[r] = max(dp[r], dp[l] + money);
            }
            dp[r] = max(dp[r], dp[r - 1]);
        }
        return dp[n];
    }
};
