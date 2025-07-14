class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<pair<int, int>> dp1(n, {0, 0}), dp2(n, {0, 0});
        
        // Always rob 1st
        dp1[1] = {0, nums[0]};
        for(int i = 2; i < n - 1; i++) {
            dp1[i] = {dp1[i - 1].second + nums[i], max(dp1[i - 1].first, dp1[i - 1].second)};
        }
        if(n > 2) dp1[n - 1] = dp1[n - 2];
        // Always not rob 1st
        dp2[1] = {nums[1], 0};
        for(int i = 2; i < n; i++) {
            dp2[i] = {dp2[i - 1].second + nums[i], max(dp2[i - 1].first, dp2[i - 1].second)};
        }
        
        return max(max(dp1[n - 1].first, dp1[n - 1].second), max(dp2[n - 1].first, dp2[n - 1].second));
    }
};
