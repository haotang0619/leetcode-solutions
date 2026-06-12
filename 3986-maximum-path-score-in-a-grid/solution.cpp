class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size(), ans = -1;
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(k + 1, -1)));
        dp[0][0][0] = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int c = 0; c <= k; c++) {
                    int val = grid[i][j];
                    if(val == 0) {
                        if(i > 0) dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c]);
                        if(j > 0) dp[i][j][c] = max(dp[i][j][c], dp[i][j - 1][c]);
                    } else if(c > 0) {
                        if(i > 0 && dp[i - 1][j][c - 1] > -1) {
                            dp[i][j][c] = max(dp[i][j][c], dp[i - 1][j][c - 1] + val);
                        }
                        if(j > 0 && dp[i][j - 1][c - 1] > -1) {
                            dp[i][j][c] = max(dp[i][j][c], dp[i][j - 1][c - 1] + val);
                        }
                    }
                    if(i == m - 1 && j == n - 1) {
                        ans = max(ans, dp[i][j][c]);
                    }
                }
            }
        }
        return ans;
    }
};
