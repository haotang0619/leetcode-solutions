class Solution {
public:
    int getDist(int a, int b) {
        if(a == 0 || b == 0) return 0;
        int x1 = (a - 1) / 6, y1 = (a - 1) % 6;
        int x2 = (b - 1) / 6, y2 = (b - 1) % 6;
        return abs(x1 - x2) + abs(y1 - y2);
    }
    
    int minimumDistance(string word) {
        int n = word.size();
        int dp[n + 1][27][27];
        fill_n(&dp[0][0][0], (n + 1) * 27 * 27, INT_MAX);
        dp[0][0][0] = 0;
        int ans = INT_MAX;
        for(int i = 1; i <= n; i++) {
            int idx = word[i - 1] - 'A' + 1;
            for(int x = 0; x <= 26; x++) {
                for(int y = 0; y <= 26; y++) {
                    if(dp[i - 1][x][y] == INT_MAX) continue;
                    dp[i][idx][y] = min(dp[i][idx][y], dp[i - 1][x][y] + getDist(x, idx));
                    dp[i][x][idx] = min(dp[i][x][idx], dp[i - 1][x][y] + getDist(y, idx));
                    if(i == n) ans = min(ans, min(dp[i][idx][y], dp[i][x][idx]));
                }
            }
        }
        return ans;
    }
};
