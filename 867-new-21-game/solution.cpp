class Solution {
public:
    // Saw editorial
    double new21Game(int n, int k, int maxPts) {
        if(k == 0) return 1;
        vector<double> dp(n + 1);
        dp[0] = 1;
        double s = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = s / maxPts;
            if(i < k) s += dp[i];
            if(i >= maxPts && i - maxPts < k) s -= dp[i - maxPts];
        }
        return accumulate(dp.begin() + k, dp.end(), 0.0);
    }
};
