class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {0, 0}));
        for(int i = 0; i < m; i++) {
            int rowX = 0, rowY = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 'X') rowX++;
                else if(grid[i][j] == 'Y') rowY++;
                dp[i][j] = {rowX, rowY};
                if(i > 0) {
                    dp[i][j].first += dp[i - 1][j].first;
                    dp[i][j].second += dp[i - 1][j].second;
                }
                ans += dp[i][j].first == dp[i][j].second && dp[i][j].first > 0 ? 1 : 0;
            }
        }
        return ans;
    }
};
