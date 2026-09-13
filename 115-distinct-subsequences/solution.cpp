class Solution {
public:
    const int mod = 1e9 + 7;
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        if(n < m) return 0;

        vector<int> dp(m, 0);
        for(int i = 0; i < n; i++) {
            for(int j = min(i, m - 1); j >= 0; j--) {
                if(s[i] == t[j]) dp[j] = (dp[j] + (j == 0 ? 1 : dp[j - 1])) % mod;
            }
        }
        return dp[m - 1];
    }
};
