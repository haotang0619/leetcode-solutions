class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i = m - 1; i >= 0; i--) {
            for(int j = n - 1; j >= 0; j--) {
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else {
                    if(j == n - 1) dp[i][j] = 1;
                    else dp[i][j] = dp[i][j + 1] + 1;
                }
            }
        }
        int max_now = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int now = 0;
                int len = dp[i][j];
                for(int k = i; k < m; k++) {
                    len = min(len, dp[k][j]);
                    if(len >= k - i + 1) now = k - i + 1;
                    else break;
                }
                max_now = max(max_now, now);
            }
        }
        return max_now * max_now;
    }
};
