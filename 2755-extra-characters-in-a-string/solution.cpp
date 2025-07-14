class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size(), m = dictionary.size();
        vector<pair<int, int>> dp(n + 1, {n, n});
        for(int i = 1; i <= n; i++) {
            dp[i].second = min(dp[i - 1].first, dp[i - 1].second);
            for(auto x : dictionary) {
                int len = x.size();
                if(i - len >= 0) {
                    bool flag = true;
                    for(int j = 0; j < len; j++) {
                        if(s[i - len + j] != x[j]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) {
                        dp[i].first = min(dp[i].first, min(dp[i - len].first, dp[i - len].second) - len);
                    }
                }
            }
        }
        return min(dp[n].first, dp[n].second);
    }
};
