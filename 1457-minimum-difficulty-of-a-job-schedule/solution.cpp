class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(n < d) return -1;
        vector<vector<int>> dp(d, vector<int>(n, INT_MAX));
        for(int j = 0; j < n; j++) {
            dp[0][j] = j == 0 ? jobDifficulty[j] : max(dp[0][j - 1], jobDifficulty[j]);
        }
        for(int i = 1; i < d; i++) {
            for(int j = n - 1; j >= i; j--) {
                int maxNow = jobDifficulty[j];
                for(int k = j - 1; k >= i - 1; k--) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + maxNow);
                    maxNow = max(maxNow, jobDifficulty[k]);
                }
            }
        }
        return dp[d - 1][n - 1];
    }
};
