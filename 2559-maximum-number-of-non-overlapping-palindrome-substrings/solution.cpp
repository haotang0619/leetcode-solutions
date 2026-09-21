class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n, 0);
        for(int i = 0; i < n; i++) {
            if(i > 0) dp[i] = max(dp[i], dp[i - 1]);
            
            // i as the center
            for(int l = i, r = i; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                int len = r - l + 1;
                if(len >= k) dp[r] = max(dp[r], (l > 0 ? dp[l - 1] : 0) + 1);
            }

            // i, i + 1 as the center
            for(int l = i, r = i + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++) {
                int len = r - l + 1;
                if(len >= k) dp[r] = max(dp[r], (l > 0 ? dp[l - 1] : 0) + 1);
            }
        }
        return dp[n - 1];
    }
};
