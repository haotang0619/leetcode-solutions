class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<int> best(sum + 1, 0), dp(sum + 1, INT_MAX);
        dp[0] = 0;
        int cnt = 1;
        for(auto& num : nums) {
            vector<int> dp1 = dp;
            if(num <= sum && best[num] <= cnt) {
                for(int op = 0, now = num; now <= sum; op++, now *= 2) {
                    for(int x = 0; x + now <= sum; x++) {
                        if(dp[x] == INT_MAX) continue;
                        if(dp1[x + now] == INT_MAX) cnt++;
                        dp1[x + now] = min(dp1[x + now], dp[x] + op);
                    }
                    if(best[num] == cnt) break;
                }
                best[num] = cnt;
            }
            for(int op = 0, now = num; now >= 1; op++, now /= 2) {
                for(int x = 0; x + now <= sum; x++) {
                    if(dp[x] == INT_MAX) continue;
                    if(dp1[x + now] == INT_MAX) cnt++;
                    dp1[x + now] = min(dp1[x + now], dp[x] + op);
                }
            }
            dp = dp1;
        }
        return dp[sum] == INT_MAX ? -1 : dp[sum];
    }
};
