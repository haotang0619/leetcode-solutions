class Solution {
public:
    int mod = 1e9 + 7;
    // Try using DP to count invalid partitions
    int countPartitions(vector<int>& nums, int k) {
        long long totalCnt = 1;
        for(int i = 1; i <= nums.size(); i++) totalCnt = (totalCnt * 2) % mod;
        totalCnt = (totalCnt - 2 + mod) % mod;
        
        long long total = accumulate(nums.begin(), nums.end(), 0LL);
        long long cnt = 0;
        vector<long long> dp(k, 0);
        dp[0] = 1;
        for(auto x : nums) {
            for(int i = k - 1; i >= x; i--) {
                int prev = i - x;
                if(prev >= 0 && dp[prev] > 0) {
                    dp[i] = (dp[i] + dp[prev]) % mod;
                    if(total - i == 0) continue;
                    if(total - i >= k) cnt = (cnt + dp[prev] * 2) % mod;
                    else cnt = (cnt + dp[prev]) % mod;
                }
            }
        }
        return (totalCnt - cnt + mod) % mod;
    }
};
