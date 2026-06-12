// Asked GPT for Digit DP
class Solution {
public:
    using ll = long long;

    // pair<ll, ll> -> [numbers count, sum of waviness]
    // type: 0 -> trailing zero, 1 -> peak, 2 -> valley
    pair<ll, ll> dfs(string &s, pair<ll, ll> memo[20][2][11][3], int pos, bool tight, int prev, int type) {
        if (pos == s.size()) return {1, 0};
        if (memo[pos][tight][prev][type].first != -1) {
            return memo[pos][tight][prev][type];
        }
        ll cnt = 0, w = 0;
        int limit = tight ? s[pos] - '0' : 9;
        for (int digit = 0; digit <= limit; digit++) {
            bool nextTight = tight && (digit == limit);
            // From a trailing zero:
            if(prev == 10) {
                auto res = dfs(s, memo, pos + 1, nextTight, digit == 0 ? 10 : digit, 0);
                cnt += res.first, w += res.second;
            } else {
                int nextType = 0;
                if(digit > prev) nextType = 1;
                else if(digit < prev) nextType = 2;
                ll add = 0;
                if(type != 0 && nextType != 0 && nextType != type) add = 1;
                auto res = dfs(s, memo, pos + 1, nextTight, digit, nextType);
                cnt += res.first, w += res.second + res.first * add;
            }
        }
        return memo[pos][tight][prev][type] = {cnt, w};
    }

    ll digitDP(ll n) {
        if (n < 0) return 0;
        string s = to_string(n);
        pair<ll, ll> memo[20][2][11][3];
        memset(memo, -1, sizeof(memo));
        return dfs(s, memo, 0, true, 10, 0).second;
    }

    long long totalWaviness(long long num1, long long num2) {
        return digitDP(num2) - digitDP(num1 - 1);
    }
};
