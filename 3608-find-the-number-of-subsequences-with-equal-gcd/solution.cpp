// Saw a solution
class Solution {
public:
    int mod = 1e9 + 7;
    int subsequencePairCount(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(mx + 1, vector<int>(mx + 1, 0)), dp1;
        dp[0][0] = 1;
        for(auto& num : nums) {
            dp1 = dp;
            for(int i = 0; i <= mx; i++) {
                for(int j = 0; j <= mx; j++) {
                    dp1[gcd(i, num)][j] = (dp1[gcd(i, num)][j] + dp[i][j]) % mod;
                    dp1[i][gcd(j, num)] = (dp1[i][gcd(j, num)] + dp[i][j]) % mod;
                }
            }
            dp = dp1;
        }
        int ans = 0;
        for(int i = 1; i <= mx; i++) ans = (ans + dp[i][i]) % mod;
        return ans;
    }
};
