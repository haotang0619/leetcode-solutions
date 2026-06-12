class Solution {
public:
    int minFlips(string s) {
        int ans = INT_MAX, n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));
        
        // x == 0: we DO NOT flip the 1st, x == 1: we FLIP the 1st
        for(int x = 0; x < 2; x++) {
            if(x == 0) {
                if(s[0] == '0') dp[0][0][0] = 0;
                else dp[0][1][0] = 0;
            } else {
                // reset dp status
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < 2; j++) { 
                        for(int k = 0; k < 2; k++) dp[i][j][k] = -1;
                    }
                }
                if(s[0] == '0') dp[0][1][0] = 1;
                else dp[0][0][0] = 1;
            }
            
            for(int i = 1; i < n; i++) {
                if(s[i] == '0') {
                    // Not flipping
                    if(dp[i - 1][1][0] >= 0) dp[i][0][0] = dp[i - 1][1][0];
                    if(dp[i - 1][0][0] >= 0) dp[i][0][1] = dp[i - 1][0][0];
                    if(dp[i - 1][1][1] >= 0) {
                        if(dp[i][0][1] == -1) dp[i][0][1] = dp[i - 1][1][1];
                        else dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][1]);
                    }
                    // flipping
                    if(dp[i - 1][0][0] >= 0) dp[i][1][0] = dp[i - 1][0][0] + 1;
                    if(dp[i - 1][1][0] >= 0) dp[i][1][1] = dp[i - 1][1][0] + 1;
                    if(dp[i - 1][0][1] >= 0) {
                        if(dp[i][1][1] == -1) dp[i][1][1] = dp[i - 1][0][1] + 1;
                        else dp[i][1][1] = min(dp[i][1][1], dp[i - 1][0][1] + 1);
                    }
                } else {
                    // Not flipping
                    if(dp[i - 1][0][0] >= 0) dp[i][1][0] = dp[i - 1][0][0];
                    if(dp[i - 1][1][0] >= 0) dp[i][1][1] = dp[i - 1][1][0];
                    if(dp[i - 1][0][1] >= 0) {
                        if(dp[i][1][1] == -1) dp[i][1][1] = dp[i - 1][0][1];
                        else dp[i][1][1] = min(dp[i][1][1], dp[i - 1][0][1]);
                    }
                    // flipping
                    if(dp[i - 1][1][0] >= 0) dp[i][0][0] = dp[i - 1][1][0] + 1;
                    if(dp[i - 1][0][0] >= 0) dp[i][0][1] = dp[i - 1][0][0] + 1;
                    if(dp[i - 1][1][1] >= 0) {
                        if(dp[i][0][1] == -1) dp[i][0][1] = dp[i - 1][1][1] + 1;
                        else dp[i][0][1] = min(dp[i][0][1], dp[i - 1][1][1] + 1);
                    }
                }
            }
            for(int i = 0; i < 2; i++) {
                for(int j = 0; j < 2; j++) {
                    if(j == 1) {
                        int head = s[0] == '0' ? 0 : 1;
                        if(x == 1) head = 1 - head;
                        if(i == head) continue;
                    }
                    if(dp[n - 1][i][j] == -1) continue;
                    ans = min(ans, dp[n - 1][i][j]);
                }
            }
        }
        return ans;
    }
};
