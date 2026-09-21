class Solution {
public:
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, INT_MAX));
        
        // base cases, i = 1 & 2
        dp[1][0] = max(0, max(nums[0], nums[2]) + 1 - nums[1]);
        if(n > 3) {
            dp[2][1] = max(0, max(nums[1], nums[3]) + 1 - nums[2]);
        }

        // DP
        for(int i = 3; i < n - 1; i++) {
            if(i % 2 == 0) {
                if(n & 1) continue;
                int mx = max(nums[i - 1], nums[i + 1]);
                int need = max(0, mx + 1 - nums[i]);
                dp[i][1] = min(dp[i - 2][1], dp[i - 3][0]) + need;
            } else {
                int mx = max(nums[i - 1], nums[i + 1]);
                int need = max(0, mx + 1 - nums[i]);
                dp[i][0] = dp[i - 2][0] + need;
            }
        }

        if(n & 1) return dp[n - 2][0];
        return min(dp[n - 3][0], dp[n - 2][1]);
    }
};
