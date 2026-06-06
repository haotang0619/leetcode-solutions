class Solution {
public:
    int mod = 1e9 + 7;

    // Saw all hints
    int numberOfWays(int n, int x) {
        int bound = ceil(pow(n, (double)1 / x));
        vector<vector<int>> dp(n + 1, vector<int>(bound + 1, 0));
        for(int j = 0; j <= bound; j++) dp[0][j] = 1;
        for(int i = 1; i <= n; i++) {
            // j: the biggest possible number we use is <= j
            for(int j = 1; j <= bound; j++) {
                int left = i - pow(j, x);
                if(left < 0) dp[i][j] = dp[i][j - 1];
                else dp[i][j] = (dp[i][j - 1] + dp[left][j - 1]) % mod;
            }
        }
        return dp[n][bound];
    }
};
