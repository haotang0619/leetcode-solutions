class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for(int i = 1; i <= n; i++) {
            for(auto &w : wordDict) {
                int m = w.size();
                if(i - m >= 0 && s.substr(i - m, m) == w) dp[i] = dp[i] || dp[i - m];
            }
        }
        return dp[n];
    }
};
