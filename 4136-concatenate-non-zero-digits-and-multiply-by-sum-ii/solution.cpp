class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<long long> pSum1(n + 1, 0), pSum2(n + 1, 0), powers(n + 1, 1);
        vector<int> digits(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            int now = s[i - 1] - '0';
            pSum1[i] = (pSum1[i - 1] + now) % mod;
            if(now != 0) {
                pSum2[i] = (pSum2[i - 1] * 10 + now) % mod;
                digits[i] = digits[i - 1] + 1;
            } else {
                pSum2[i] = pSum2[i - 1];
                digits[i] = digits[i - 1];
            }
            powers[i] = powers[i - 1] * 10 % mod;
        }
        int m = queries.size();
        vector<int> ans(m);
        for(int i = 0; i < m; i++) {
            int x = queries[i][0], y = queries[i][1];
            long long a = (pSum1[y + 1] - pSum1[x]) % mod;
            long long b = (pSum2[y + 1] - pSum2[x] * powers[digits[y + 1] - digits[x]]) % mod;
            ans[i] = ((a * b % mod) + mod) % mod;
        }
        return ans;
    }
};
