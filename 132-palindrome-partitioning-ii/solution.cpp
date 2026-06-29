class Solution {
public:
    using ull = unsigned long long;
    int base = 131;

    int minCut(string s) {
        int n = s.size();
        vector<ull> rh1(n + 1, 0), rh2(n + 1, 0), pow;
        ull p = 1;
        for(int i = 1; i <= n; i++) {
            int j = n - i;
            rh1[i] = rh1[i - 1] * base + (s[i - 1] - 'a' + 1);
            rh2[j] = rh2[j + 1] * base + (s[j] - 'a' + 1);
            pow.push_back(p);
            p *= base;
        }
        pow.push_back(p);
        vector<vector<int>> prev(n);
        for(int j = 0; j < n; j++) {
            for(int i = 0; i <= j; i++) {
                ull h1 = rh1[j + 1] - rh1[i] * pow[j - i + 1];
                ull h2 = rh2[i] - rh2[j + 1] * pow[j - i + 1];
                if(h1 == h2) prev[j].push_back(i);
            }
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = -1;
        for(int i = 1; i <= n; i++) {
            for(auto& p : prev[i - 1]) dp[i] = min(dp[i], dp[p] + 1);
        }
        return dp[n];
    }
};
