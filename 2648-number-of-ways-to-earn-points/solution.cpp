class Solution {
public:
    int mod = 1e9 + 7;
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        vector<long long> dp(target + 1, 0);
        dp[0] = 1;
        for(auto& type : types) {
            vector<long long> dp1 = dp;
            int cnt = type[0], mark = type[1];
            for(int i = 0; i <= target; i++) {
                for(int j = 1; j <= cnt; j++) {
                    int tar = i + mark * j;
                    if(tar > target) break;
                    dp1[tar] = (dp1[tar] + dp[i]) % mod;
                }
            }
            dp = dp1;
        }
        return dp[target];
    }
};
