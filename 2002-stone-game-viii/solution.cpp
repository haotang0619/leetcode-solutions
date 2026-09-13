// Saw all hints and asked GPT
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + stones[i - 1];
        vector<int> dp(n + 1, 0);
        dp[n - 1] = pSum[n];
        int mx = max(pSum[n - 1] - dp[n - 1], pSum[n] - dp[n]);
        for(int i = n - 2; i >= 1; i--) dp[i] = mx, mx = max(mx, pSum[i] - dp[i]);
        return dp[1];
    }
};
