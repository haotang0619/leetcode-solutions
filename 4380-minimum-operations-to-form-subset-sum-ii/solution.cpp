class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> dp(sum + 1, INT_MAX);
        dp[0] = 0;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vector<int> dp1 = dp;
            int prev = nums[i];
            for(int op = 0, now = nums[i]; now >= 1; op++, now /= 2) {
                for(int op1 = 0, now1 = now; now1 <= sum; op1++, now1 *= 2) {
                    for(int x = 0; x + now1 <= sum; x++) {
                        if(dp[x] == INT_MAX) continue;
                        dp1[x + now1] = min(dp1[x + now1], dp[x] + op + op1);
                    }
                    if(op != 0 && now * 2 == prev) break;
                }
                prev = now;
            }
            dp = dp1;
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};
