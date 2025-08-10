class Solution {
public:
    // Trying to handle the 2nd and 3rd child separately turned out to be surprisingly correct.
    // => They only intersect at the diagonal but it doesn't matter
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        // First child
        int ans = 0, n = fruits.size();
        for(int i = 0; i < n; i++) {
            ans += fruits[i][i];
            fruits[i][i] = 0;
        }
        
        // Second child
        int m = (n + 1) / 2;
        vector<int> dp(m, 0);
        dp[0] = fruits[0][n - 1];
        for(int t = 1; t < n; t++) {
            vector<int> newDp(m, 0);
            int maxM = t < m ? t : n - 1 - t;
            for(int i = 0; i <= maxM; i++) {
                int collected = fruits[t][n - 1 - i];
                for(int x = i - 1; x <= i + 1; x++) {
                    if(x < 0 || x >= m) continue;
                    newDp[i] = max(newDp[i], dp[x] + collected);
                }
            }
            dp = newDp;
        }
        ans += dp[0];

        // Third child
        dp = vector<int>(m, 0);
        dp[0] = fruits[n - 1][0];
        for(int t = 1; t < n; t++) {
            vector<int> newDp(m, 0);
            int maxM = t < m ? t : n - 1 - t;
            for(int i = 0; i <= maxM; i++) {
                int collected = fruits[n - 1 - i][t];
                for(int x = i - 1; x <= i + 1; x++) {
                    if(x < 0 || x >= m) continue;
                    newDp[i] = max(newDp[i], dp[x] + collected);
                }
            }
            dp = newDp;
        }
        return ans + dp[0];
    }
};
