class Solution {
public:
    int minDays(int n) {
        vector<int> v = {1};
        while(v.back() < n) v.push_back(v.back() + v.size() + 1);
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = -1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < v.size(); j++) {
                if(i - v[j] < 0) break;
                int prev = dp[i - v[j]];
                dp[i] = min(dp[i], prev + 1 + j + 1);
            }
        }
        return dp[n];
    }
};
