class Solution {
public:
    // Saw solutions
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        if(n == 1) return 1;
        int size = 1 << n;
        vector<vector<int>> dp(size, vector<int>(sessionTime + 1, 100));
        for(int i = 0; i < n; i++) {
            int idx = 1 << i;
            dp[idx][tasks[i]] = 1;
        }
        int ans = 100;
        for(int i1 = 2; i1 <= n; i1++) {
            for(int i2 = 0; i2 < size; i2++) {
                int cnt = 0, i3 = i2;
                while(i3 > 0) {
                    cnt += i3 & 1;
                    i3 >>= 1;
                }
                if(cnt != i1) continue;
                int mask = size - 1;
                for(int j = 0; j < n; j++) {
                    int prev = (i2 & (mask - (1 << j)));
                    if(i2 == prev) continue;
                    for(int t = 0; t <= sessionTime; t++) {
                        // New session
                        dp[i2][tasks[j]] = min(dp[i2][tasks[j]], dp[prev][t] + 1);
                        if(i1 == n) ans = min(ans, dp[i2][tasks[j]]);
                        // Same session
                        int t1 = t + tasks[j];
                        if(t1 <= sessionTime) {
                            dp[i2][t1] = min(dp[i2][t1], dp[prev][t]);
                            if(i1 == n) ans = min(ans, dp[i2][t1]);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
