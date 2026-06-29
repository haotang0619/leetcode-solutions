// Asked GPT
// Also checked the testcase 717 to understand the errors in the original submissions
class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        // [Not yet started, Middle of mul, Middle of div, Already ended]
        vector<vector<long long>> dp(n, vector<long long>(4, LLONG_MIN));
        long long ans = LLONG_MIN;
        for(int i = 0; i < n; i++) {
            dp[i][0] = (i > 0 ? dp[i - 1][0] : 0) + nums[i];
            ans = max(ans, dp[i][0]);
            if(dp[i][0] < 0) dp[i][0] = 0;
            
            dp[i][1] = (i > 0 ? max(dp[i - 1][0], dp[i - 1][1]) : 0) + (long long)nums[i] * k;
            ans = max(ans, dp[i][1]);
            if(dp[i][1] < 0) dp[i][1] = 0;
            
            dp[i][2] = (i > 0 ? max(dp[i - 1][0], dp[i - 1][2]) : 0) + nums[i] / k;
            ans = max(ans, dp[i][2]);
            if(dp[i][2] < 0) dp[i][2] = 0;
            
            dp[i][3] = (i > 0 ? max(dp[i - 1][1], dp[i - 1][2]) : 0) + nums[i];
            if(i > 0 && dp[i - 1][3] > LLONG_MIN) {
                dp[i][3] = max(dp[i][3], dp[i - 1][3] + nums[i]);
            }
            ans = max(ans, dp[i][3]);
            if(dp[i][3] < 0) dp[i][3] = 0;
        }
        return ans;
    }
};
