class Solution {
public:
    int mod = 1e9 + 7;
    
    int countStableSubsequences(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(4, 0)); // [odd1, odd2, even1, even2]
        for(int i = 0; i < n; i++) {
            if(i == 0) {
                if(nums[i] & 1) dp[i][0] = 1;
                else dp[i][2] = 1;
                continue;
            }
            dp[i] = dp[i - 1];
            if(nums[i] & 1) {
                dp[i][0] = (dp[i][0] + dp[i - 1][2] + dp[i - 1][3] + 1) % mod;
                dp[i][1] = (dp[i][1] + dp[i - 1][0]) % mod;
            } else {
                dp[i][2] = (dp[i][2] + dp[i - 1][0] + dp[i - 1][1] + 1) % mod;
                dp[i][3] = (dp[i][3] + dp[i - 1][2]) % mod;
            }
        }
        return accumulate(dp[n - 1].begin(), dp[n - 1].end(), 0LL) % mod;
    }
};
