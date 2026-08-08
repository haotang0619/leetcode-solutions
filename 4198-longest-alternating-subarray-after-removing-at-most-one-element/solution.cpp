class Solution {
public:
    int longestAlternating(vector<int>& nums) {
        int n = nums.size();
        // [peak_not_deleted, valley_not_deleted, peak_has_deleted, valley_has_deleted]
        vector<vector<int>> dp(n, vector<int>(4, 0));
        for(int i = 0; i < n; i++) dp[i][0] = dp[i][1] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[i - 1]) {
                // As a valley
                dp[i][1] = max(dp[i][1], dp[i - 1][0] + 1);
                dp[i][3] = max(dp[i][3], dp[i - 1][2] + 1);
            } else if(nums[i] > nums[i - 1]) {
                // As a peak
                dp[i][0] = max(dp[i][0], dp[i - 1][1] + 1);
                dp[i][2] = max(dp[i][2], dp[i - 1][3] + 1);
            }
            // Last one is deleted
            if(i >= 2) {
                if(nums[i] < nums[i - 2]) {
                    // As a valley
                    dp[i][3] = max(dp[i][3], dp[i - 2][0] + 1);
                } else if(nums[i] > nums[i - 2]) {
                    // As a peak
                    dp[i][2] = max(dp[i][2], dp[i - 2][1] + 1);
                }
            }
            for(int j = 0; j < 4; j++) ans = max(ans, dp[i][j]);
        }
        return ans;
    }
};
