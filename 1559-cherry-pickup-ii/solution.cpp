class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int ans = 0, m = grid.size(), n = grid[0].size();
        int dp[m][n][n];
        memset(dp, -1, sizeof(dp));
        dp[0][0][n - 1] = grid[0][0] + grid[0][n - 1];
        for(int r = 1; r < m; r++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    if(dp[r - 1][i][j] == -1) continue;
                    for(int x = i - 1; x <= i + 1; x++) {
                        for(int y = j - 1; y <= j + 1; y++) {
                            if(x < 0 || x >= n || y < 0 || y >= n) continue;
                            int now = dp[r - 1][i][j];
                            now += grid[r][x];
                            if(x != y) now += grid[r][y];
                            dp[r][x][y] = max(dp[r][x][y], now);
                            if(r == m - 1) ans = max(ans, dp[r][x][y]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
