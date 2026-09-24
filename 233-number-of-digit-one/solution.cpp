class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        int sz = s.size();
        int memo[sz + 1][sz + 1][2];
        fill_n(&memo[0][0][0], (sz + 1) * (sz + 1) * 2, -1);
        auto dfs = [&](auto&& self, int pos, int oneCnt, bool tight) {
            if(pos == sz) return oneCnt;
            if(memo[pos][oneCnt][tight] != -1) return memo[pos][oneCnt][tight];
            int ans = 0, limit = tight ? (s[pos] - '0') : 9;
            for(int d = 0; d <= limit; d++) {
                bool nextTight = tight && (d == limit);
                ans += self(self, pos + 1, oneCnt + (d == 1), nextTight);
            }
            return memo[pos][oneCnt][tight] = ans;
        };
        return dfs(dfs, 0, 0, true);
    }
};
