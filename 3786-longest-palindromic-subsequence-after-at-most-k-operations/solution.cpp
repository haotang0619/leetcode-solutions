class Solution {
public:
    // Saw all hints
    int longestPalindromicSubsequence(string s, int k) {
        int n = s.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(k + 1, 1)));
        for(int l = 0; l <= k; l++) {
            for(int gap = 0; gap < n; gap++) {
                for(int i = 0; i + gap < n; i++) {
                    int j = i + gap;
                    if(i + 1 <= j) {
                        dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j][l]);
                        dp[i][j][l] = max(dp[i][j][l], dp[i][j - 1][l]);
                    }
                    int diff = abs(int(s[i]) - int(s[j]));
                    diff = min(diff, 26 - diff);
                    int last = l - diff;
                    if(i + 1 <= j - 1) {
                        if(last >= 0) {
                            dp[i][j][l] = max(dp[i][j][l], dp[i + 1][j - 1][last] + 2);
                        }
                    } else if(i == j - 1 && diff <= l) {
                        dp[i][j][l] = max(dp[i][j][l], 2);
                    }
                }
            }
        }
        return dp[0][n - 1][k];
    }
};
