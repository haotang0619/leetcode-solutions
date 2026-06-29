class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<vector<double>> dp(101, vector<double>(101, 0));
        dp[0][0] = poured;
        int r = 0;
        while(r <= query_row) {
            bool valid = true;
            for(int g = 0; g <= r; g++) {
                if(dp[r][g] > 1) {
                    valid = false;
                    dp[r + 1][g] += (dp[r][g] - 1) / 2;
                    dp[r + 1][g + 1] += (dp[r][g] - 1) / 2;
                    dp[r][g] = 1;
                }
            }
            if(valid) break;
            r++;
        }
        return dp[query_row][query_glass];
    }
};
