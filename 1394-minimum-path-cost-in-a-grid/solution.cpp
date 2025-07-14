class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        int ans = INT_MAX;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int now = grid[i][j];
                if(i == 0) dp[i][j] = now;
                else {
                    for(int k = 0; k < n; k++) {
                        int prev = grid[i - 1][k];
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[prev][j] + now);
                    }
                }
                if(i == m - 1) ans = min(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
