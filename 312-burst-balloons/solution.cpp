// Saw discussions and asked GPT for the Matrix-Chain Multiplication Algo
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size() - 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = 2; len <= n; len++) {
            for(int l = 0; l <= n - len; l++) {
                int r = l + len - 1;
                for(int m = l; m < r; m++) {
                    dp[l][r] = max(dp[l][r], dp[l][m] + dp[m + 1][r] + nums[l] * nums[m + 1] * nums[r + 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};
