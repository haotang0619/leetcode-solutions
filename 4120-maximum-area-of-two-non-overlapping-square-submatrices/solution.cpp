class Solution {
public:
    int maxArea(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<vector<int>>> dp(4, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        // Top-Bottom
        for(int i = 1; i <= m; i++) {
            for(int j = 1; j <= n; j++) {
                if(mat[i - 1][j - 1] == 0) continue;
                dp[0][i][j] = min({
                    dp[0][i - 1][j], dp[0][i][j - 1], dp[0][i - 1][j - 1]
                }) + 1;
            }
        }
        // Bottom-Top
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(mat[i][j] == 0) continue;
                dp[1][i][j] = min({
                    dp[1][i + 1][j], dp[1][i][j + 1], dp[1][i + 1][j + 1]
                }) + 1;
            }
        }
        // Left-Right
        for(int j = 1; j <= n; j++) {
            for(int i = 1; i <= m; i++) {
                if(mat[i - 1][j - 1] == 0) continue;
                dp[2][i][j] = min({
                    dp[2][i - 1][j], dp[2][i][j - 1], dp[2][i - 1][j - 1]
                }) + 1;
            }
        }
        // Right-Left
        for(int j = n - 1; j >= 0; j--) {
            for(int i = m - 1; i >= 0; i--) {
                if(mat[i][j] == 0) continue;
                dp[3][i][j] = min({
                    dp[3][i + 1][j], dp[3][i][j + 1], dp[3][i + 1][j + 1]
                }) + 1;
            }
        }
        vector<vector<int>> dpRows(2, vector<int>(m, 0)), dpCols(2, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 1; j <= n; j++) dpRows[0][i] = max(dpRows[0][i], dp[0][i + 1][j]);
            if(i > 0) dpRows[0][i] = max(dpRows[0][i], dpRows[0][i - 1]);
        }
        for(int i = m - 1; i >= 0; i--) {
            for(int j = 0; j < n; j++) dpRows[1][i] = max(dpRows[1][i], dp[1][i][j]);
            if(i < m - 1) dpRows[1][i] = max(dpRows[1][i], dpRows[1][i + 1]);
        }
        for(int j = 0; j < n; j++) {
            for(int i = 1; i <= m; i++) dpCols[0][j] = max(dpCols[0][j], dp[2][i][j + 1]);
            if(j > 0) dpCols[0][j] = max(dpCols[0][j], dpCols[0][j - 1]);
        }
        for(int j = n - 1; j >= 0; j--) {
            for(int i = 0; i < m; i++) dpCols[1][j] = max(dpCols[1][j], dp[3][i][j]);
            if(j < n - 1) dpCols[1][j] = max(dpCols[1][j], dpCols[1][j + 1]);
        }
        int len = 0;
        for(int i = 0; i < m - 1; i++) len = max(len, min(dpRows[0][i], dpRows[1][i + 1]));
        for(int j = 0; j < n - 1; j++) len = max(len, min(dpCols[0][j], dpCols[1][j + 1]));
        return len * len;
    }
};
