class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1, false);
        dp[0] = false;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= i / j; j++) {
                dp[i] = dp[i] || (!dp[i - j * j]);
            }
        }
        return dp[n];
    }
};
