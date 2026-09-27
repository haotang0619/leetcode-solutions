class Solution {
public:
    using pii = pair<int, int>;
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<pii> dp(n, {1, 1});
        pii mx = {0, 0};
        for(int r = 0; r < n; r++) {
            pii mxNow = {0, 1};
            for(int l = 0; l < r; l++) {
                if(nums[l] >= nums[r]) continue;
                if(dp[l].first > mxNow.first) mxNow = dp[l];
                else if(dp[l].first == mxNow.first) mxNow.second += dp[l].second;
            }
            mxNow.first++, dp[r] = mxNow;
            if(mxNow.first > mx.first) mx = mxNow;
            else if(mxNow.first == mx.first) mx.second += mxNow.second;
        }
        return mx.second;
    }
};
