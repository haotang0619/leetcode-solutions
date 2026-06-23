class Solution {
public:
    long long dfs(string &s, vector<vector<vector<long long>>> &memo, int pos, bool tight, int prev, int k) {
        if (pos == s.size()) return 1;
        if (memo[pos][tight][prev] != -1) return memo[pos][tight][prev];
        long long ans = 0;
        int limit = tight ? s[pos] - '0' : 9;
        for (int digit = 0; digit <= limit; digit++) {
            bool nextTight = tight && (digit == limit);
            // From a trailing zero:
            if(prev == 10) {
                ans += dfs(s, memo, pos + 1, nextTight, digit == 0 ? 10 : digit, k);
            }
            else {
                if(abs(digit - prev) > k) continue;
                ans += dfs(s, memo, pos + 1, nextTight, digit, k);
            }
        }
        return memo[pos][tight][prev] = ans;
    }

    long long digitDP(long long n, int k) {
        if (n < 0) return 0;
        string s = to_string(n);
        vector<vector<vector<long long>>> memo(s.size() + 1, vector<vector<long long>>(2, vector<long long>(11, -1)));
        return dfs(s, memo, 0, true, 10, k);
    }

    long long goodIntegers(long long l, long long r, int k) {
        return digitDP(r, k) - digitDP(l - 1, k);
    }
};
