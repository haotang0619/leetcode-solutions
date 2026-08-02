class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfRoutes(vector<string>& grid, int d) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int i = n - 1; i >= 0; i--) {
            // First visit
            if(i == n - 1) {
                for(int j = 0; j < m; j++) dp[i][j] = (grid[i][j] == '.');
            } else {
                vector<int> pSum(m + 1, 0);
                for(int j = 1; j <= m; j++) {
                    pSum[j] = (pSum[j - 1] + dp[i + 1][j - 1]) % mod;
                }
                for(int j = 0; j < m; j++) {
                    if(grid[i][j] == '#') continue;
                    double range = sqrt(d * d - 1);
                    int l = max(0, (int)ceil(j - range));
                    int r = min(m - 1, (int)floor(j + range));
                    dp[i][j] = (pSum[r + 1] - pSum[l]) % mod;
                }
            }
            // Second visit
            vector<int> pSum(m + 1, 0);
            for(int j = 1; j <= m; j++) {
                pSum[j] = (pSum[j - 1] + dp[i][j - 1]) % mod;
            }
            vector<int> tmp = dp[i];
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '#') continue;
                int l = max(0, j - d), r = min(m - 1, j + d);
                int add = (pSum[r + 1] - pSum[l]) % mod;
                add = (add - dp[i][j]) % mod;
                tmp[j] = (tmp[j] + add) % mod;
            }
            dp[i] = tmp;
        }
        int ans = 0;
        for(int i = 0; i < m; i++) ans = (ans + dp[0][i]) % mod;
        return ans < 0 ? ans + mod : ans;
    }
};
