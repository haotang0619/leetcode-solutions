// Figured out by myself:
// k eggs, n floors
// 1. drop at xth floor, not broken => 1 + dp[k][n - x]
// 2. drop at xth floor, broken     => 1 + dp[k - 1][x - 1]
// => dp[k][n] = min of max(1 + dp[k][n - x], 1 + dp[k - 1][x - 1]) from 1 to n
// KEY: dp[i][j - x] is non-increasing, dp[i - 1][x - 1] is non-decreasing
// => Use binary search to find the value crosses in the 2 arrays

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));
        iota(dp[1].begin(), dp[1].end(), 0); // base case for 1 egg only
        for(int i = 0; i <= k; i++) dp[i][0] = 0; // base case for 0 floors

        // DP
        for(int i = 2; i <= k; i++) {
            for(int j = 1; j <= n; j++) {
                int l = 1, r = j;
                while(l < r) {
                    int m = l + (r - l) / 2;
                    if(dp[i - 1][m - 1] < dp[i][j - m]) l = m + 1;
                    else r = m;
                }
                int val = dp[i - 1][l - 1];
                if(l > 1) val = min(val, dp[i][j - (l - 1)]);
                dp[i][j] = 1 + val;
            }
        }
        return dp[k][n];
    }
};
