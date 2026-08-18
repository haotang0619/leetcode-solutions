class Solution {
public:
    int mod = 1e9 + 7;
    int countCoprime(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> dp(151, 0);
        for(int i = 0; i < m; i++) {
            vector<int> dp1(151, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0) dp1[mat[i][j]]++;
                else {
                    for(int k = 1; k <= 150; k++) {
                        if(dp[k] == 0) continue;
                        int idx = gcd(k, mat[i][j]);
                        dp1[idx] = (dp1[idx] + dp[k]) % mod;
                    }
                }
            }
            dp = dp1;
        }
        return dp[1];
    }
};
