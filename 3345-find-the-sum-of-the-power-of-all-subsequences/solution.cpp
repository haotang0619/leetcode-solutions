class Solution {
public:
    int mod = 1e9 + 7;
    int sumOfPower(vector<int>& nums, int k) {
        int n = nums.size();
        // [len, sum]
        vector<vector<int>> dp(k + 1, vector<int>(k + 1, 0));
        dp[0][0] = 1;
        for(int i = 0; i < n; i++) {
            for(int len = k; len >= 1; len--) {
                for(int x = 0; x <= k; x++) {
                    int y = x - nums[i];
                    if(y >= 0 && y <= k) {
                        dp[len][x] = (dp[len][x] + dp[len - 1][y]) % mod;
                    }
                }
            }
        }
        long long ans = 0;
        vector<long long> pows(n + 1, 1);
        for(int x = 1; x <= n; x++) pows[x] = (pows[x - 1] * 2) % mod;
        for(int len = 1; len <= min(n, k); len++) {
            long long cnt = dp[len][k];
            ans = (ans + cnt * pows[n - len]) % mod;
        }
        return ans;
    }
};
