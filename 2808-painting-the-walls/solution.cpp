// Saw editorial
class Solution {
public:
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        // [ith paint][walls covered] => min cost
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for(int i = 1; i <= n; i++) dp[n][i] = 1e9;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = 1; j <= n; j++) {
                int paid = cost[i] + dp[i + 1][max(0, j - 1 - time[i])];
                int dontPaid = dp[i + 1][j];
                dp[i][j] = min(paid, dontPaid);
            }
        }
        return dp[0][n];
    }
};
