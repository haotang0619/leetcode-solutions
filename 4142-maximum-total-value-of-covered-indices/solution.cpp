class Solution {
public:
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(3, 0));
        // idx == 0: it's a 0;
        // idx == 1: it's a 1 and not moved;
        // idx == 2: it's a 1 and moved
        if(s[0] == '1') dp[0][1] = nums[0];
        for(int i = 1; i < n; i++) {
            if(s[i] == '0') {
                if(s[i - 1] == '0') dp[i][0] = dp[i - 1][0];
                else dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]);
            } else {
                if(s[i - 1] == '0') {
                    dp[i][1] = dp[i - 1][0] + nums[i];
                    dp[i][2] = dp[i - 1][0] + nums[i - 1];
                } else {
                    dp[i][1] = max(dp[i - 1][1], dp[i - 1][2]) + nums[i];
                    dp[i][2] = max(dp[i - 1][1], dp[i - 1][2] + nums[i - 1]);
                }
            }
        }
        return max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2]));
    }
};
