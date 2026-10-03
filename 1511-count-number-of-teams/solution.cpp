class Solution {
public:
    int numTeams(vector<int>& rating) {
        int ans = 0, n = rating.size();
        int dp[2][3][n];
        fill_n(&dp[0][0][0], 2 * 3 * n, 0);
        fill_n(&dp[0][0][0], n, 1);
        fill_n(&dp[1][0][0], n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(rating[j] < rating[i]) {
                    dp[0][1][i] += dp[0][0][j], dp[0][2][i] += dp[0][1][j];
                } else if(rating[j] > rating[i]) {
                    dp[1][1][i] += dp[1][0][j], dp[1][2][i] += dp[1][1][j];
                }
            }
            ans += dp[0][2][i] + dp[1][2][i];
        }
        return ans;
    }
};
