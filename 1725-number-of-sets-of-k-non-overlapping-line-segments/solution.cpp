class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfSets(int n, int K) {
        int dp[K + 1][n];
        for(int i = 0; i < n; i++) dp[1][i] = i;
        for(int k = 2; k <= K; k++) {
            int pSum = 0, poss = 0;
            for(int i = 0; i < n; i++) {
                dp[k][i] = poss;
                pSum = (pSum + dp[k - 1][i]) % mod;
                poss = (poss + pSum) % mod;
            }
        }
        int ans = 0;
        for(auto& x : dp[K]) ans = (ans + x) % mod;
        return ans;
    }
};
