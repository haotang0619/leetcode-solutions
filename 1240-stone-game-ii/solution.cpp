class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> pSum(n + 1, 0);
        for(int i = 1; i <= n; i++) pSum[i] = pSum[i - 1] + piles[i - 1];
        int maxM = (n + 1) / 2;
        vector<vector<int>> dp(n, vector<int>(maxM + 1, 0));
        for(int i = n - 1; i >= 0; i--) {
            for(int m = maxM; m >= 1; m--) {
                for(int x = min(2 * m, n - i); x >= 1; x--) {
                    int suffixSum = pSum[n] - pSum[i];
                    int sub = 0;
                    if(i + x < n) sub = dp[i + x][min(max(m, x), maxM)];
                    dp[i][m] = max(dp[i][m], suffixSum - sub);
                }
            }
        }
        return dp[0][1];
    }
};
