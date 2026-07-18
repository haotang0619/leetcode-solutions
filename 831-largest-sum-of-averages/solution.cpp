class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<double>> dp(n, vector<double>(k + 1, 0));
        double sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            dp[i][1] = (sum / (i + 1));
        }
        double ans = dp[n - 1][1];
        for(int i = 2; i <= k; i++) {
            for(int j = i - 2; j < n; j++) {
                double sum = 0;
                for(int l = j + 1; l < n; l++) {
                    sum += nums[l];
                    dp[l][i] = max(dp[l][i], dp[j][i - 1] + sum / (l - j));
                    if(l == n - 1) ans = max(ans, dp[l][i]);
                }
            }
        }
        return ans;
    }
};
