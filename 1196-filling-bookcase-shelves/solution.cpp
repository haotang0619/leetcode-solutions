class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size(), ans = 1e7;
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 1e7)); // [layer][until_idx]
        dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j <= n; j++) {
                if(dp[i - 1][j] == 1e7) break;
                int w = 0, h = 0;
                for(int k = j + 1; k <= n; k++) {
                    w += books[k - 1][0];
                    if(w > shelfWidth) break;
                    h = max(h, books[k - 1][1]);
                    dp[i][k] = min(dp[i][k], dp[i - 1][j] + h);
                    if(k == n) ans = min(ans, dp[i][k]);
                }
            }
        }
        return ans;
    }
};
