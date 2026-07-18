class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) return *min_element(matrix[0].begin(), matrix[0].end());

        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0].assign(matrix[0].begin(), matrix[0].end());
        
        int ans = INT_MAX;
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = max(0, j - 1); k < min(n, j + 2); k++) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + matrix[i][j]);
                    if(i == n - 1) ans = min(ans, dp[i][j]);
                }
            }
        }
        return ans;
    }
};
