class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0), dp(k, 0);
        // dp[x]: count of subarrays whose products mod k = x by far
        for(auto& num : nums) {
            vector<long long> dp1(k, 0);
            for(long long x = 0; x < k; x++) dp1[x * num % k] += dp[x];
            dp1[num % k]++, dp = dp1;
            for(int x = 0; x < k; x++) ans[x] += dp[x];
        }
        return ans;
    }
};
