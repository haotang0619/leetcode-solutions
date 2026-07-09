class Solution {
public:
    bool canMakeSubsequence(string s, string t) {
        int n = t.size(), m = s.size();
        // s idx of [changed, not changed]
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        dp[0][0] = 0, dp[0][1] = s[0] == t[0] ? 0 : -1;
        for(int i = 1; i < n; i++) {
            int i1 = dp[i - 1][0], i2 = dp[i - 1][1];
            if(i1 >= m - 1 || i2 >= m - 1) return true;
            // Change here:
            dp[i][0] = dp[i - 1][1] + 1;
            
            // No change here:
            if(s[i1 + 1] == t[i]) dp[i][0] = max(dp[i][0], i1 + 1);
            else dp[i][0] = max(dp[i][0], i1);
            if(s[i2 + 1] == t[i]) dp[i][1] = i2 + 1;
            else dp[i][1] = i2;
        }
        return dp[n - 1][0] == m - 1 || dp[n - 1][1] == m - 1;
    }
};
