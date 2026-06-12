class Solution {
public:
    int mod = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<vector<long long>>> dp(m, vector<vector<long long>>(n, vector<long long>(2, -1)));

        if(grid[0][0] > 0) dp[0][0][0] = grid[0][0];
        else if(grid[0][0] < 0) dp[0][0][1] = abs(grid[0][0]);
        else dp[0][0] = {0, 0};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 && j == 0) continue;
                long long val = grid[i][j], v = abs(val);
                if(val == 0) dp[i][j] = {0, 0};
                else {
                    if(i > 0) {
                        if(dp[i - 1][j][0] > -1) {
                            int k = val > 0 ? 0 : 1;
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][0] * v);
                        }
                        if(dp[i - 1][j][1] > -1) {
                            int k = val > 0 ? 1 : 0;
                            dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j][1] * v);
                        }
                    }
                    if(j > 0) {
                        if(dp[i][j - 1][0] > -1) {
                            int k = val > 0 ? 0 : 1;
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][0] * v);
                        }
                        if(dp[i][j - 1][1] > -1) {
                            int k = val > 0 ? 1 : 0;
                            dp[i][j][k] = max(dp[i][j][k], dp[i][j - 1][1] * v);
                        }
                    }
                }
            }
        }
        return dp[m - 1][n - 1][0] % mod;
    }
};
