class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if(n == 1) return s1 == s2 ? 0 : s1 > s2 ? -1 : 1;
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= n; i++) {
            if(s1[i - 1] == s2[i - 1]) {
                if(i == 2 && s1[i - 2] == '1' && s2[i - 2] == '0') dp[i] = 2;
                else dp[i] = dp[i - 1];
            } else if(s1[i - 1] == '0') dp[i] = dp[i - 1] + 1;
            else {
                // From prev 2:
                if(i >= 2) {
                    if(s1[i - 2] == '0' && s2[i - 2] == '0') dp[i] = dp[i - 2] + 2;
                    else if(s1[i - 2] == '0' && s2[i - 2] == '1') dp[i] = dp[i - 2] + 3;
                    else if(s1[i - 2] == '1' && s2[i - 2] == '0') dp[i] = dp[i - 2] + 1;
                    else if(s1[i - 2] == '1' && s2[i - 2] == '1') dp[i] = dp[i - 2] + 2;
                }
                // From prev 1:
                dp[i] = min(dp[i], dp[i - 1] + 2);
            }
        }
        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
