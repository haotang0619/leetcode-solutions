class Solution {
public:
    vector<vector<int>> next = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4}
    };
    int mod = 1e9 + 7;
    
    int knightDialer(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(10, 0));
        dp[1].assign(10, 1);
        for(int i = 2; i <= n; i++) {
            for(int d = 0; d <= 9; d++) {
                for(auto& d1 : next[d]) {
                    dp[i][d1] = (dp[i][d1] + dp[i - 1][d]) % mod;
                }
            }
        }
        int ans = 0;
        for(int d = 0; d <= 9; d++) ans = (ans + dp[n][d]) % mod;
        return ans;
    }
};
