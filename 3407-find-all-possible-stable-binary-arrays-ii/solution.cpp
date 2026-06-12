class Solution {
public:
    int mod = 1e9 + 7;

    // Same as 3129
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(zero + 1, vector<vector<long long>>(one + 1, vector<long long>(2, 0)));
        
        for(int z = 0; z <= min(zero, limit); z++) dp[z][0][0] = 1;
        for(int o = 0; o <= min(one, limit); o++) dp[0][o][1] = 1;

        for(int z = 1; z <= zero; z++) {
            for(int o = 1; o <= one; o++) {
                // Put a zero here
                dp[z][o][0] += dp[z - 1][o][0] + dp[z - 1][o][1];
                if(z > limit) dp[z][o][0] -= dp[z - limit - 1][o][1];
                // Put a one here
                dp[z][o][1] += dp[z][o - 1][0] + dp[z][o - 1][1];
                if(o > limit) dp[z][o][1] -= dp[z][o - limit - 1][0];
                dp[z][o][0] %= mod;
                dp[z][o][1] %= mod;
            }
        }
        long long ans = (dp[zero][one][0] + dp[zero][one][1]) % mod;
        return ans < 0 ? ans + mod : ans;
    }
};
