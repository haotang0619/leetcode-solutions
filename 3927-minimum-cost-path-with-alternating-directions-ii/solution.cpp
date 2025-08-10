class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& waitCost) {
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        dp[0][0] = 1;
        for(long long i = 0; i < m; i++) {
            for(long long j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                long long entry = (i + 1) * (j + 1);
                long long wait = i == m - 1 && j == n - 1 ? 0 : waitCost[i][j];
                if(i > 0) {
                    long long l = dp[i - 1][j] + entry + wait;
                    if(dp[i][j] == -1) dp[i][j] = l;
                    dp[i][j] = min(dp[i][j], l);
                }
                if(j > 0) {
                    long long u = dp[i][j - 1] + entry + wait;
                    if(dp[i][j] == -1) dp[i][j] = u;
                    dp[i][j] = min(dp[i][j], u);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};
