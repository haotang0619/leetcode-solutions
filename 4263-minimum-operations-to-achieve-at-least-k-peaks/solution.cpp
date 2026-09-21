class Solution {
public:
    int minOperations(vector<int>& nums, int K) {
        int n = nums.size();
        long long dp[K + 1][2][2][2]; // [peak count][idx][idx is peak][0 is peak]
        fill_n(&dp[0][0][0][0], (K + 1) * 2 * 2 * 2, INT_MAX);
        dp[0][0][0][0] = 0;
        for(int i = 0; i < n; i++) {
            int prev = nums[(i - 1 + n) % n], next = nums[(i + 1) % n];
            int need = max(0, max(prev, next) + 1 - nums[i]);
            for(int k = 0; k <= min(K, i); k++) {
                int now = i % 2, old = 1 - now;
                
                // Not making it a peak
                if(i > 0) {
                    dp[k][now][0][0] = min(dp[k][old][0][0], dp[k][old][1][0]);
                    dp[k][now][0][1] = min(dp[k][old][0][1], dp[k][old][1][1]);
                }
                if(k == K) continue;
                
                // Make it a peak
                if(i == 0) {
                    dp[k + 1][now][1][1] = need;
                } else if(i == n - 1) {
                    dp[k + 1][now][1][0] = dp[k][old][0][0] + need;
                } else {
                    dp[k + 1][now][1][0] = dp[k][old][0][0] + need;
                    dp[k + 1][now][1][1] = dp[k][old][0][1] + need;
                }
            }
        }
        long long ans = INT_MAX;
        for(int x = 0; x < 2; x++) {
            for(int y = 0; y < 2; y++) ans = min(ans, dp[K][(n - 1) % 2][x][y]);
        }
        return ans >= INT_MAX ? -1 : ans;
    }
};
