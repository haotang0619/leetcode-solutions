class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int n = stations.size();
        long long dp[n + 1][n + 1];
        memset(dp, -1, sizeof(dp));
        dp[0][0] = startFuel;
        int prevPos = 0;
        for(int i = 1; i <= n; i++) {
            int cost = stations[i - 1][0] - prevPos;
            for(int j = 0; j <= i; j++) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j] - cost);
                if(j > 0 && dp[i - 1][j - 1] - cost >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] - cost + stations[i - 1][1]);
                }
            }
            prevPos = stations[i - 1][0];
        }
        int lastCost = target - (n > 0 ? stations.back()[0] : 0);
        for(int i = 0; i <= n; i++) {
            if(dp[n][i] >= lastCost) return i;
        }
        return -1;
    }
};
