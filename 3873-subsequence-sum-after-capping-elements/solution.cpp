class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> ans(n, false);
        vector<bool> dp(k + 1, false);
        dp[0] = true;
        int idx = 0;
        for(int i = 1; i <= n; i++) {
            while(idx < n && nums[idx] <= i) {
                for(int x = k; x >= nums[idx]; x--) {
                    if(dp[x - nums[idx]]) dp[x] = true;
                }
                idx++;
            }
            int left = n - idx;
            for(int x = k; x >= max(0, k - left * i); x -= i) {
                if(dp[x]) {
                    ans[i - 1] = true;
                    break;
                }
            }
        }
        return ans;
    }
};
