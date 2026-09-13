class Solution {
public:
    const int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int ans = 0, n = s.size();
        vector<int> dp(26, 0);
        for(auto& c : s) {
            int idx = c - 'a', tmp = ans;
            int added = (tmp + 1 - dp[idx]) % mod;
            ans = (ans + added) % mod;
            dp[idx] = (tmp + 1) % mod;
        }
        return ans < 0 ? (ans + mod) : ans;
    }
};
