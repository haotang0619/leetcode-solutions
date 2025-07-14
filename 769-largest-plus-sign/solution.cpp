class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(4, 0)));
        vector<vector<int>> grids(n, vector<int>(n, 1));
        for(auto x : mines) grids[x[0]][x[1]] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grids[i][j] == 0) {
                    dp[i][j][0] = 0;
                    dp[i][j][1] = 0;
                } else {
                    if(i > 0) dp[i][j][0] = dp[i - 1][j][0] + 1;
                    else dp[i][j][0] = 1;
                    if(j > 0) dp[i][j][1] = dp[i][j - 1][1] + 1;
                    else dp[i][j][1] = 1;
                }
                int x = n - 1 - i, y = n - 1 - j;
                if(grids[x][y] == 0) {
                    dp[x][y][2] = 0;
                    dp[x][y][3] = 0;
                } else {
                    if(x < n - 1) dp[x][y][2] = dp[x + 1][y][2] + 1;
                    else dp[x][y][2] = 1;
                    if(y < n - 1) dp[x][y][3] = dp[x][y + 1][3] + 1;
                    else dp[x][y][3] = 1;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                int now = min(min(dp[i][j][0], dp[i][j][1]), min(dp[i][j][2], dp[i][j][3]));
                ans = max(ans, now);
            }
        }
        return ans;
    }
};
