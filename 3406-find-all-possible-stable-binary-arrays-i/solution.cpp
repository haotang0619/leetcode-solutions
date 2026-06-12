class Solution {
public:
    int mod = 1e9 + 7;

    // Saw editorial, reduce O(N * Z * O) to O(Z * O)
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(zero + 1, vector<long long>(one + 1, 0)));
        
        for(int z = 0; z <= min(zero, limit); z++) dp[0][z][0] = 1;
        for(int o = 0; o <= min(one, limit); o++) dp[1][0][o] = 1;

        for(int z = 1; z <= zero; z++) {
            for(int o = 1; o <= one; o++) {
                // Put a zero here
                dp[0][z][o] += dp[0][z - 1][o];
                dp[0][z][o] += dp[1][z - 1][o];
                if(z > limit) dp[0][z][o] -= dp[1][z - limit - 1][o];
                // Put a one here
                dp[1][z][o] += dp[0][z][o - 1];
                dp[1][z][o] += dp[1][z][o - 1];
                if(o > limit) dp[1][z][o] -= dp[0][z][o - limit - 1];
                dp[0][z][o] %= mod;
                dp[1][z][o] %= mod;
            }
        }
        long long ans = (dp[0][zero][one] + dp[1][zero][one]) % mod;
        return ans < 0 ? ans + mod : ans;
    }
};
