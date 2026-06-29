class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(), maxVal = INT_MIN;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MIN));
        vector<int> maxInCol(n + 1, 0);
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int j = 0; j <= n; j++) dp[0][j] = 0;
        for(int i = 1; i <= m; i++) {
            int maxByFar = 0;
            for(int j = 1; j <= n; j++) {
                int val = nums1[i - 1] * nums2[j - 1];
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j - 1] + val);
                dp[i][j] = max(maxByFar, dp[i][j]);
                dp[i][j] = max(maxInCol[j], dp[i][j]);
                maxByFar = dp[i][j];
                maxInCol[j] = max(maxInCol[j], dp[i][j]);
                maxVal = max(maxVal, val);
            }
        }
        return dp[m][n] == 0 ? maxVal : dp[m][n];
    }
};
