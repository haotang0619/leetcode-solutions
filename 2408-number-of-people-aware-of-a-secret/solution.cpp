class Solution {
public:
    int mod = 1e9 + 7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<int>> dp(2, vector<int>(forget, 0));
        dp[0][forget - 1] = 1;
        int now = 1, prev = 0;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < forget - 1; j++) dp[now][j] = dp[prev][j + 1];
            dp[now][forget - 1] = 0;
            for(int j = 1; j <= forget - delay; j++) {
                dp[now][forget - 1] = (dp[now][forget - 1] + dp[prev][j]) % mod;
            }
            now = 1 - now;
            prev = 1 - prev;
        }
        int ans = 0;
        for(auto x : dp[prev]) ans = (ans + x) % mod;
        return ans;
    }
};
