class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + nums[i - 1];
        if(k == 1) return pSum[n];
        vector<vector<pair<int, int>>> dp(n - 1, vector<pair<int, int>>(k));
        // for cut = 1
        for(int i = 0; i < n - 1; i++) {
            int sum1 = pSum[i + 1] - pSum[0], sum2 = pSum[n] - pSum[i + 1];
            dp[i][1] = {sum1, sum2};
        }
        // for cut >= 2
        for(int cut = 2; cut < k; cut++) {
            for(int i = cut - 1; i < n - 1; i++) {
                int sum2 = pSum[n] - pSum[i + 1];
                for(int j = 0; j < i; j++) {
                    int sum1 = max(pSum[i + 1] - pSum[j + 1], dp[j][cut - 1].first);
                    if(j == 0) dp[i][cut] = {sum1, sum2};
                    else if(sum1 < dp[i][cut].first) dp[i][cut].first = sum1;
                }
            }
        }
        int ans = INT_MAX;
        for(int i = k - 2; i < n - 1; i++) ans = min(ans, max(dp[i][k - 1].first, dp[i][k - 1].second));
        return ans;
    }
};
